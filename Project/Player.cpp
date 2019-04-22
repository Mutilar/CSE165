#include "Player.h"
#include <iostream>
#include <vector>
#include <math.h>

Player::Player()
{
	this->position = new Point(1000, 1000);
	this->rotation = 0;
	this->velocity = new Point(0, 0);

	this->clipping_check_start = new Point(0, 0);
	this->clipping_check_end = new Point(0, -90);

	this->ground_check_start = new Point(0, -90);
	this->ground_check_end = new Point(0, -100);
}

void Player::step(std::vector<Line *> &lines)
{
	Point *c_s = this->toRelativeSpace(this->clipping_check_start);
	Point *c_e = this->toRelativeSpace(this->clipping_check_end);

	Point *m_s = this->toRelativeSpace(this->ground_check_start);
	Point *m_e = this->toRelativeSpace(this->ground_check_end);

	float slope_contacted = 0;
	bool clip_hit = false, middle_hit = false;
	Line *line;

	for (std::vector<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		line = *it;
		if (this->IsIntersecting(line->getStartPoint(), line->getEndPoint(), m_s, m_e))
		{
			slope_contacted = (line->getEndPoint().getY() - line->getStartPoint().getY()) / (line->getEndPoint().getX() - line->getStartPoint().getX());
			middle_hit = true;
			break;
		}
	}
	if (middle_hit)
	{
		std::cout << "Grounded, going " << this->velocity->getX() << "\n";
		this->velocity->shiftX(slope_contacted);
		this->velocity->shiftY(slope_contacted);
	}
	else
	{
		this->velocity->shiftY(-1);
	}
	this->shift(this->velocity);

	while (true)
	{
		clip_hit = false;
		for (std::vector<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
		{
			line = *it;
			if (this->IsIntersecting(line->getStartPoint(), line->getEndPoint(), c_s, c_e))
			{
				clip_hit = true;
				this->shift(new Point(0, 1));
				break;
			}
		}
		if (clip_hit == false)
		{
			break;
		}
	}
}

bool Player::IsIntersecting(Point *a, Point *b, Point *c, Point *d)
{
	float denominator = ((b->getX() - a->getX()) * (d->getY() - c->getY())) - ((b->getY() - a->getY()) * (d->getX() - c->getX()));
	float numerator1 = ((a->getY() - c->getY()) * (d->getX() - c->getX())) - ((a->getX() - c->getX()) * (d->getY() - c->getY()));
	float numerator2 = ((a->getY() - c->getY()) * (b->getX() - a->getX())) - ((a->getX() - c->getX()) * (b->getY() - a->getY()));

	// Detect coincident lines (has a problem, read below)
	if (denominator == 0)
		return numerator1 == 0 && numerator2 == 0;

	float r = numerator1 / denominator;
	float s = numerator2 / denominator;

	return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
}

void Player::drawSet(int *points, int num_points, Point *camera_position, int r, int g, int b)
{
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	int min_x = points[0], min_y = points[1], max_x = points[0], max_y = points[1];
	for (int i = 0; i < num_points; i += 2)
	{
		if (points[i] < min_x)
			min_x = points[i];
		if (points[i] > max_x)
			max_x = points[i];

		if (points[i + 1] < min_y)
			min_y = points[i + 1];
		if (points[i + 1] > max_y)
			max_y = points[i + 1];

		float x = points[i] - 150; //246/2;
		float y = 300 - points[i + 1];
		Point *relative_point = this->toRelativeSpace(new Point(x, y));
		glVertex2f(camera_position->getX() + relative_point->getX(), camera_position->getY() + relative_point->getY());
	}
	//std::cout << "min: " << min_x << "," << min_y << "; max: " << max_x << ", " << max_y << "\n";
	glEnd();
}

Point *Player::toRelativeSpace(Point *point)
{
	return new Point(this->getPositionX() + cos(rotation) * point->getX() + sin(rotation) * point->getY(), this->getPositionY() + -sin(rotation) * point->getX() + cos(rotation) * point->getY());
}

void Player::draw(Point *camera_position)
{

	int eye_points[] = {172, 112, 174, 107, 179, 105, 184, 107, 187, 112, 185, 117, 179, 119, 174, 117};
	int scarf_points_1[] = {5, 155, 35, 160, 30, 188, 0, 180};
	int scarf_points_2[] = {50, 160, 74, 145, 88, 166, 66, 180};
	int scarf_points_3[] = {95, 142, 118, 136, 118, 133, 133, 133, 133, 163, 118, 163, 102, 166};
	int scarf_points_4[] = {150, 133, 163, 133, 163, 163, 150, 163};
	int scarf_points_5[] = {179, 133, 194, 133, 194, 163, 179, 163};
	int beak_points[] = {206, 109, 237, 121, 209, 128};
	int hat_overlay_points[] = {119, 80, 124, 68, 130, 61, 143, 53, 153, 51, 161, 51, 175, 56, 188, 68, 194, 80};
	int chest_overlay_points[] = {154, 96, 197, 96, 205, 113, 207, 120, 207, 125, 204, 130, 198, 133, 188, 133, 188, 240, 125, 240, 125, 133, 154, 133};
	int hat_points[] = {144, 38, 148, 30, 155, 27, 162, 30, 166, 38, 162, 46, 159, 48, 151, 48, 147, 46};
	int chest_points[] = {109, 88, 111, 83, 116, 80, 119, 71, 128, 59, 136, 53, 149, 49, 165, 49, 176, 53, 184, 59, 194, 71, 197, 80, 202, 83, 204, 88, 202, 92, 199, 95, 204, 104, 209, 118, 209, 126, 206, 131, 199, 135, 191, 136, 191, 243, 175, 243, 218, 287, 240, 281, 246, 288, 216, 316, 141, 243, 122, 243, 122, 136, 119, 135, 119, 95, 114, 94, 111, 92};

	drawSet(eye_points, sizeof(eye_points) / sizeof(*eye_points), camera_position, 0, 0, 1);
	drawSet(scarf_points_1, sizeof(scarf_points_1) / sizeof(*scarf_points_1), camera_position, 1, 0, 0);
	drawSet(scarf_points_2, sizeof(scarf_points_2) / sizeof(*scarf_points_2), camera_position, 1, 0, 0);
	drawSet(scarf_points_3, sizeof(scarf_points_3) / sizeof(*scarf_points_3), camera_position, 1, 0, 0);
	drawSet(scarf_points_4, sizeof(scarf_points_4) / sizeof(*scarf_points_4), camera_position, 1, 0, 0);
	drawSet(scarf_points_5, sizeof(scarf_points_5) / sizeof(*scarf_points_5), camera_position, 1, 0, 0);
	drawSet(beak_points, sizeof(beak_points) / sizeof(*beak_points), camera_position, 1, 0, 0);
	drawSet(hat_overlay_points, sizeof(hat_overlay_points) / sizeof(*hat_overlay_points), camera_position, 1, 1, 1);
	drawSet(chest_overlay_points, sizeof(chest_overlay_points) / sizeof(*chest_overlay_points), camera_position, 1, 1, 1);
	drawSet(hat_points, sizeof(hat_points) / sizeof(*hat_points), camera_position, 0, 0, 0);
	drawSet(chest_points, sizeof(chest_points) / sizeof(*chest_points), camera_position, 0, 0, 0);

	Point *m_s = this->toRelativeSpace(this->ground_check_start);
	Point *m_e = this->toRelativeSpace(this->ground_check_end);
	this->drawRaycast(m_s, m_e, camera_position);
}

void Player::drawRaycast(Point *start, Point *end, Point *camera_position)
{

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(start->getX() + camera_position->getX(), start->getY() + camera_position->getY());
	glVertex2f(end->getX() + camera_position->getX(), end->getY() + camera_position->getY());
	glEnd();
}

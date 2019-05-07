#include "Player.h"
#include <iostream>
#include <vector>
#include <math.h>

Player::Player()
{

	this->position = new Point(200, 2000);
	this->rotation = 0;
	this->velocity = new Point(0, 0);

	this->clipping_ray = new Line(new Point(0, 0), new Point(0, -90));
	this->ground_check_ray = new Line(new Point(0, -90), new Point(0, -100));
}

void Player::step(std::vector<Line *> &lines)
{
	float slope_contacted = 0;
	bool clip_hit = false, middle_hit = false;

	Line *hit = getIntersectingLine(lines, this->toRelativeSpace(ground_check_ray));
	if (hit != NULL)
	{
		if (hit->getEndPoint()->getX() > hit->getStartPoint()->getX())
		{
			slope_contacted = 1.0 * (hit->getEndPoint()->getY() - hit->getStartPoint()->getY()) / (hit->getEndPoint()->getX() - hit->getStartPoint()->getX());
		}
		else
		{
			slope_contacted = -1.0 * (hit->getEndPoint()->getY() - hit->getStartPoint()->getY()) / (hit->getStartPoint()->getX() - hit->getEndPoint()->getX());
		}
		middle_hit = true;
	}
	if (middle_hit)
	{
		//std::cout << "Grounded, on slope " << slope_contacted << "\n";
		this->velocity->shiftX(-slope_contacted);
		// this->velocity->setY(-slope_contacted);
	}
	else
	{
		this->velocity->shiftY(-.5);
	}

	this->shift(this->velocity);

	while (true)
	{
		clip_hit = false;
		Line *hit = getIntersectingLine(lines, this->toRelativeSpace(clipping_ray));
		if (hit != NULL)
		{
			this->shift(new Point(0, 1));
		}
		else
		{
			break;
		}
	}
	if (middle_hit)
	{
		int count = 0;
		while (count < 20)
		{
			count++;
			Line *hit = getIntersectingLine(lines, this->toRelativeSpace(ground_check_ray));
			if (hit == NULL)
			{
				this->shift(new Point(0, -1));
			}
			else
			{
				break;
			}
		}
	}
}

Line *Player::getIntersectingLine(std::vector<Line *> &lines, Line *ray)
{
	Line *line;
	for (std::vector<Line *>::iterator it = lines.begin(); it != lines.end(); ++it)
	{
		Line *line = *it;
		if (this->IsIntersecting(line, ray))
		{
			return line;
		}
	}
	return NULL;
}

bool Player::IsIntersecting(Line *a, Line *b)
{
	return this->IsIntersecting(a->getStartPoint(), a->getEndPoint(), b->getStartPoint(), b->getEndPoint());
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
	// std::cout << "min: " << min_x << "," << min_y << "; max: " << max_x << ", " << max_y << "\n";
	glEnd();
}

Point *Player::toRelativeSpace(Point *point)
{
	return new Point(this->getPositionX() + cos(rotation) * point->getX() + sin(rotation) * point->getY(), this->getPositionY() + -sin(rotation) * point->getX() + cos(rotation) * point->getY());
}

Line *Player::toRelativeSpace(Line *line)
{
	return new Line(this->toRelativeSpace(line->getStartPoint()), this->toRelativeSpace(line->getEndPoint()));
}

void Player::draw(Point *camera_position)
{

	PlayerBody = new TexRect("images/player.png", camera_position->getX() + this->getPositionX() - 150, camera_position->getY() + this->getPositionY() + 220, 300, 300);
	PlayerBody->draw(1.0);
}

void Player::drawRaycast(Point *start, Point *end, Point *camera_position)
{

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(start->getX() + camera_position->getX(), start->getY() + camera_position->getY());
	glVertex2f(end->getX() + camera_position->getX(), end->getY() + camera_position->getY());
	glEnd();
}

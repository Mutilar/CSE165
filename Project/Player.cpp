#include "Player.h"
#include <iostream>
#include <vector>

Player::Player()
{
}

void Player::step() {

	//cast 3 rays
	//update rotation
	//update speed

}

void Player::draw()
{ //Point* camera_position) {
}

void Player::drawSet(int* points, int num_points, Point *camera_position, int r, int g, int b) {
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_points; i += 2) glVertex2f(points[i] + camera_position->getX(), 350 - points[i + 1] + camera_position->getY());
	glEnd();
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
	int chest_overlay_points[] = { 154, 96, 197, 96, 205, 113, 207, 120, 207, 125, 204, 130, 198, 133, 188, 133, 188, 240, 125, 240, 125, 133, 154, 133};
	int hat_points[] = {144, 38, 148, 30, 155, 27, 162, 30, 166, 38, 162, 46, 159, 48, 151, 48, 147, 46 };
	int chest_points[] = {109, 88, 111, 83, 116, 80, 119, 71, 128, 59, 136, 53, 149, 49, 165, 49, 176, 53, 184, 59, 194, 71, 197, 80, 202, 83, 204, 88, 202, 92, 199, 95, 204, 104, 209, 118, 209, 126, 206, 131, 199, 135, 191, 136, 191, 243, 175, 243, 218, 287, 240, 281, 246, 288, 216, 316, 141, 243, 122, 243, 122, 136, 119, 135, 119, 95, 114, 94, 111, 92 };
	
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
	
}
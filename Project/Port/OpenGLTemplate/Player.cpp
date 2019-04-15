#include "Player.h"
#include <iostream>

Player::Player() {

}

void Player::draw() {
}

void Player::draw(Point* camera_position) {
	int black_eye_points[] = { 172, 112, 174, 107, 179, 105, 184, 107, 187, 112, 185, 117, 179, 119, 174, 117 };
	int i = 0;	
//Eye
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (i = 0; i < (sizeof(black_eye_points)/sizeof(*black_eye_points)); i += 2) {
		std::cout << black_eye_points[i] + camera_position->getX() << "test\n";
		glVertex2f(black_eye_points[i] + camera_position->getX(), 350 - black_eye_points[i + 1] + camera_position->getY());
	} 
	//glVertex2f(172, 350 - 112);
	//glVertex2f(174, 350 - 107);
	//glVertex2f(179, 350 - 105);
	//glVertex2f(184, 350 - 107);
	//glVertex2f(187, 350 - 112);
	//glVertex2f(185, 350 - 117);
	//glVertex2f(179, 350 - 119);
	//glVertex2f(174, 350 - 117);
	glEnd();

	//Scarf
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(5, 350 - 155);
	glVertex2f(35, 350 - 160);
	glVertex2f(30, 350 - 188);
	glVertex2f(0, 350 - 180);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(50, 350 - 160);
	glVertex2f(74, 350 - 145);
	glVertex2f(88, 350 - 166);
	glVertex2f(66, 350 - 180);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(95, 350 - 142);
	glVertex2f(118, 350 - 136);
	glVertex2f(118, 350 - 133);
	glVertex2f(133, 350 - 133);
	glVertex2f(133, 350 - 163);
	glVertex2f(118, 350 - 163);
	glVertex2f(102, 350 - 166);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(150, 350 - 133);
	glVertex2f(163, 350 - 133);
	glVertex2f(163, 350 - 163);
	glVertex2f(150, 350 - 163);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(179, 350 - 133);
	glVertex2f(194, 350 - 133);
	glVertex2f(194, 350 - 163);
	glVertex2f(179, 350 - 163);
	glEnd();
	//Beak
	glBegin(GL_POLYGON);
	glVertex2f(206, 350 - 109);
	glVertex2f(237, 350 - 121);
	glVertex2f(209, 350 - 128);
	glEnd();

	//White
	glColor3f(1, 1, 1);
	//White Hat Part
	glBegin(GL_POLYGON);
	glVertex2f(119, 350 - 80);
	glVertex2f(124, 350 - 68);
	glVertex2f(130, 350 - 61);
	glVertex2f(143, 350 - 53);
	glVertex2f(153, 350 - 51);
	glVertex2f(161, 350 - 51);
	glVertex2f(175, 350 - 56);
	glVertex2f(188, 350 - 68);
	glVertex2f(194, 350 - 80);
	glEnd();
	//White Chest
	glBegin(GL_POLYGON);
	glVertex2f(154, 350 - 96);
	glVertex2f(197, 350 - 96);
	glVertex2f(205, 350 - 113);
	glVertex2f(207, 350 - 120);
	glVertex2f(207, 350 - 125);
	glVertex2f(204, 350 - 130);
	glVertex2f(198, 350 - 133);
	glVertex2f(188, 350 - 133);
	glVertex2f(188, 350 - 240);
	glVertex2f(125, 350 - 240);
	glVertex2f(125, 350 - 133);
	glVertex2f(154, 350 - 133);
	glEnd();

	



	//Body and Hat
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(144, 350 - 38);
	glVertex2f(148, 350 - 30);
	glVertex2f(155, 350 - 27);
	glVertex2f(162, 350 - 30);
	glVertex2f(166, 350 - 38);
	glVertex2f(162, 350 - 46);
	glVertex2f(159, 350 - 48);
	glVertex2f(151, 350 - 48);
	glVertex2f(147, 350 - 46);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(109, 350 - 88);
	glVertex2f(111, 350 - 83);
	glVertex2f(116, 350 - 80);
	glVertex2f(119, 350 - 71);
	glVertex2f(128, 350 - 59);
	glVertex2f(136, 350 - 53);
	glVertex2f(149, 350 - 49);
	glVertex2f(165, 350 - 49);
	glVertex2f(176, 350 - 53);
	glVertex2f(184, 350 - 59);
	glVertex2f(194, 350 - 71);
	glVertex2f(197, 350 - 80);
	glVertex2f(202, 350 - 83);
	glVertex2f(204, 350 - 88);
	glVertex2f(202, 350 - 92);
	glVertex2f(199, 350 - 95);
	glVertex2f(204, 350 - 104);
	glVertex2f(209, 350 - 118);
	glVertex2f(209, 350 - 126);
	glVertex2f(206, 350 - 131);
	glVertex2f(199, 350 - 135);
	glVertex2f(191, 350 - 136);
	glVertex2f(191, 350 - 243);
	glVertex2f(175, 350 - 243);
	glVertex2f(218, 350 - 287);
	glVertex2f(240, 350 - 281);
	glVertex2f(246, 350 - 288);
	glVertex2f(216, 350 - 316);
	glVertex2f(141, 350 - 243);
	glVertex2f(122, 350 - 243);
	glVertex2f(122, 350 - 136);
	glVertex2f(119, 350 - 135); //might be an issue somewhere here
	glVertex2f(119, 350 - 95);
	glVertex2f(114, 350 - 94);
	glVertex2f(111, 350 - 92);
	glEnd();
}













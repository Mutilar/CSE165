#include "Player.h"

Player::Player() {

}

void Player::draw() {

	// Set background color to black
	glClearColor(0.0, 1.0, 0.0, 1.0);

	
	//Eye
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(172, 112);
	glVertex2f(174, 107);
	glVertex2f(179, 105);
	glVertex2f(184, 107);
	glVertex2f(187, 112);
	glVertex2f(185, 117);
	glVertex2f(179, 119);
	glVertex2f(174, 117);
	glEnd();

	//Scarf
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(5, 155);
	glVertex2f(35, 160);
	glVertex2f(30, 188);
	glVertex2f(0, 180);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(50, 160);
	glVertex2f(74, 145);
	glVertex2f(88, 166);
	glVertex2f(66, 180);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(95, 142);
	glVertex2f(118, 136);
	glVertex2f(118, 133);
	glVertex2f(133, 133);
	glVertex2f(133, 163);
	glVertex2f(118, 163);
	glVertex2f(102, 166);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(150, 133);
	glVertex2f(163, 133);
	glVertex2f(163, 163);
	glVertex2f(150, 163);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(179, 133);
	glVertex2f(194, 133);
	glVertex2f(194, 163);
	glVertex2f(179, 163);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(206, 109);
	glVertex2f(237, 121);
	glVertex2f(209, 128);
	glEnd();

	//White
	glColor3f(1, 1, 1);
	//White Hat Part
	glBegin(GL_POLYGON);
	glVertex2f(119, 80);
	glVertex2f(124, 68);
	glVertex2f(130, 61);
	glVertex2f(143, 53);
	glVertex2f(153, 51);
	glVertex2f(161, 51);
	glVertex2f(175, 56);
	glVertex2f(188, 68);
	glVertex2f(194, 80);
	glEnd();
	//White Chest
	glBegin(GL_POLYGON);
	glVertex2f(154, 96);
	glVertex2f(197, 96);
	glVertex2f(205, 113);
	glVertex2f(207, 120);
	glVertex2f(207, 125);
	glVertex2f(204, 130);
	glVertex2f(198, 133);
	glVertex2f(188, 133);
	glVertex2f(188, 240);
	glVertex2f(125, 240);
	glVertex2f(125, 133);
	glVertex2f(154, 133);
	glEnd();

	



	//Body and Hat
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(144, 38);
	glVertex2f(148, 30);
	glVertex2f(155, 27);
	glVertex2f(162, 30);
	glVertex2f(166, 38);
	glVertex2f(162, 46);
	glVertex2f(159, 48);
	glVertex2f(151, 48);
	glVertex2f(147, 46);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(109, 88);
	glVertex2f(111, 83);
	glVertex2f(116, 80);
	glVertex2f(119, 71);
	glVertex2f(128, 59);
	glVertex2f(136, 53);
	glVertex2f(149, 49);
	glVertex2f(165, 49);
	glVertex2f(176, 53);
	glVertex2f(184, 59);
	glVertex2f(194, 71);
	glVertex2f(197, 80);
	glVertex2f(202, 83);
	glVertex2f(204, 88);
	glVertex2f(202, 92);
	glVertex2f(199, 95);
	glVertex2f(204, 104);
	glVertex2f(209, 118);
	glVertex2f(209, 126);
	glVertex2f(206, 131);
	glVertex2f(199, 135);
	glVertex2f(191, 136);
	glVertex2f(191, 243);
	glVertex2f(175, 243);
	glVertex2f(218, 287);
	glVertex2f(240, 281);
	glVertex2f(246, 288);
	glVertex2f(216, 316);
	glVertex2f(141, 243);
	glVertex2f(122, 243);
	glVertex2f(122, 136);
	glVertex2f(119, 135); //might be an issue somewhere here
	glVertex2f(119, 95);
	glVertex2f(114, 94);
	glVertex2f(111, 92);
	glEnd();
}













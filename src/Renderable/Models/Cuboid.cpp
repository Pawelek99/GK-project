#include "Cuboid.h"

void Cuboid::render() {
	glColor3f(0.72f, 0.57f, 0.57f);

	// Bottom
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x - this->width, this->y, this->x + this->width);
	glVertex3f(this->x + this->width, this->y, this->x + this->width);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x + this->width, this->y, this->x + this->width);
	glVertex3f(this->x + this->width, this->y, this->x - this->width);

	glEnd();

	// Left
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x - this->width, this->y, this->x + this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x + this->width);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x - this->width);

	glEnd();

	// Right
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x + this->width, this->y, this->x - this->width);
	glVertex3f(this->x + this->width, this->y, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);

	glVertex3f(this->x + this->width, this->y, this->x - this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x - this->width);

	glEnd();

	// Front
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->width, this->y, this->x + this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);

	glVertex3f(this->x - this->width, this->y, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x + this->width, this->y, this->x + this->width);

	glEnd();

	// Back
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x - this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x - this->width);

	glVertex3f(this->x - this->width, this->y, this->x - this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x - this->width);
	glVertex3f(this->x + this->width, this->y, this->x - this->width);

	glEnd();

	// Top
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->width, this->y + this->height, this->x - this->width);
	glVertex3f(this->x - this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);

	glVertex3f(this->x - this->width, this->y + this->height, this->x - this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x + this->width);
	glVertex3f(this->x + this->width, this->y + this->height, this->x - this->width);

	glEnd();
}

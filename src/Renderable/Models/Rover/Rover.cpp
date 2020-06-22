#include "Rover.h"
#include <math.h>
#include <windows.h>
#include <gl\gl.h>

Rover::Rover() {
	this->height = 20;
	this->width = 50;
}

void Rover::setPosition(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;

	this->wheelAxis[0].setPosition(this->x, this->y, this->z + this->height);
	this->wheelAxis[1].setPosition(this->x, this->y, this->z - this->height);

	this->wheelAxis[0].setSize(this->width, this->width / 25.0f);
	this->wheelAxis[1].setSize(this->width, this->width / 25.0f);

	this->wheels[0].setPosition(this->x - this->width * 0.5f - this->width / 25.0f, this->y, this->z + this->height);
	this->wheels[1].setPosition(this->x + this->width * 0.5f + this->width / 25.0f, this->y, this->z + this->height);
	this->wheels[2].setPosition(this->x - this->width * 0.5f - this->width / 25.0f, this->y, this->z - this->height);
	this->wheels[3].setPosition(this->x + this->width * 0.5f + this->width / 25.0f, this->y, this->z - this->height);

	this->wheels[0].setSize(this->width / 25.0f * 6, this->width / 25.0f * 6);
	this->wheels[1].setSize(this->width / 25.0f * 6, this->width / 25.0f * 6);
	this->wheels[2].setSize(this->width / 25.0f * 6, this->width / 25.0f * 6);
	this->wheels[3].setSize(this->width / 25.0f * 6, this->width / 25.0f * 6);
}

void Rover::renderChassis() {
	glColor3f(0.33f, 0.33f, 0.33f);

	// Bottom
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);

	glEnd();

	// Front
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z + 12.0f + this->height);
	int i = 0;
	for (float angle = 0; angle <= PI * 0.5f; angle += PI * 0.0625, i++) {
		float z = 12.0f * cos(angle);
		float y = 12.0f * sin(angle);
		if (i % 2 == 0) {
			glVertex3f(this->x - this->height * 0.8f, this->y + y + this->width / 25.0f, this->z + z + this->height);
		} else {
			glVertex3f(this->x + this->height * 0.8f, this->y + y + this->width / 25.0f, this->z + z + this->height);
		}
	}
	glVertex3f(this->x + this->height * 0.8f, this->y + 12.0f + this->width / 25.0f, this->z + this->height);

	glEnd();

	// Top front
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);

	glEnd();

	// Back
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);

	glEnd();

	// Right side
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	for (float angle = 0; angle <= PI * 0.5f; angle += PI * 0.0625) {
		float z = 12.0f * cos(angle);
		float y = 12.0f * sin(angle);
		glVertex3f(this->x + this->height * 0.8f, this->y + y + this->width / 25.0f, this->z + z + this->height);
	}

	glEnd();

	// Left side
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z + this->height);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f, this->z + this->height);
	for (float angle = 0; angle <= PI * 0.5f; angle += PI * 0.0625) {
		float z = 12.0f * cos(angle);
		float y = 12.0f * sin(angle);
		glVertex3f(this->x - this->height * 0.8f, this->y + y + this->width / 25.0f, this->z + z + this->height);
	}

	glEnd();
}

void Rover::renderSpoiler() {
	// Spoiler
	glColor3f(0.12f, 0.12f, 0.12f);
	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);

	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x - this->height * 0.8f, this->y + this->width / 25.0f + 16.0f, this->z - this->height - 10.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);

	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 10.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 4.0f);
	glVertex3f(this->x + this->height * 0.8f, this->y + this->width / 25.0f + 14.0f, this->z - this->height - 10.0f);

	glEnd();

	// Spoiler handlers

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 6.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 8.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 6.0f);

	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 6.0f, this->z - this->height);
	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 6.0f);
	glVertex3f(this->x - this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 8.0f);

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 6.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 8.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 6.0f);

	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 6.0f, this->z - this->height);
	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 6.0f);
	glVertex3f(this->x + this->height * 0.6f, this->y + this->width / 25.0f + 12.0f, this->z - this->height - 8.0f);

	glEnd();
}

void Rover::renderExhaustPipe() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(this->x + this->height * 0.4f + 2, this->y + this->width / 25.0f + 2.0f, this->z - this->height);
	int i = 0;
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625, i++) {
		float x = 2 * cos(a);
		float y = 2 * sin(a);
		if (i % 2 == 0) {
			glVertex3f(this->x + this->height * 0.4f + x, this->y + this->width / 25.0f + 2.0f + y, this->z - this->height - 3.0f);
		} else {
			glVertex3f(this->x + this->height * 0.4f + x, this->y + this->width / 25.0f + 2.0f + y, this->z - this->height);
		}
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0, 0, 0);

	glVertex3f(this->x + this->height * 0.4f, this->y + this->width / 25.0f + 2.0f, this->z - this->height - 2.0f);
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625) {
		float x = 2 * cos(a);
		float y = 2 * sin(a);
		glVertex3f(this->x + this->height * 0.4f + x, this->y + this->width / 25.0f + 2.0f + y, this->z - this->height - 2.0f);
	}

	glEnd();
}

void Rover::renderCabin() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.33f, 0.33f, 0.8f, 0.6);

	GLfloat x, y, z, alpha, beta;     
	GLfloat radius = 24.0f;
	int gradation = 20;

	for (alpha = 0.0; alpha < PI; alpha += PI / gradation) {
		glBegin(GL_TRIANGLE_STRIP);
		for (beta = 0.0; beta < 1.01 * PI; beta += PI / gradation) {
			x = radius * cos(beta) * sin(alpha);
			y = radius * sin(beta) * sin(alpha);
			z = radius * cos(alpha);
			glVertex3f(this->x + x, this->y + y + 12, this->z + z);
			x = radius * cos(beta) * sin(alpha + PI / gradation);
			y = radius * sin(beta) * sin(alpha + PI / gradation);
			z = radius * cos(alpha + PI / gradation);
			glVertex3f(this->x + x, this->y + y + 12, this->z + z);
		}
		glEnd();
	}

	glDisable(GL_BLEND);
}

void Rover::render() {
	this->wheelAxis[0].render();
	this->wheelAxis[1].render();

	glPushMatrix();
	glTranslatef(this->x - this->width * 0.5f, this->y, this->z + this->height * 0.5f);
	glRotatef(this->angle * 20, 0, 1, 0);
	glTranslatef(-(this->x - this->width * 0.5f), -this->y, -(this->z + this->height * 0.5f));

	this->wheels[0].render();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(this->x + this->width * 0.5f, this->y, this->z + this->height * 0.5f);
	glRotatef(this->angle * 20, 0, 1, 0);
	glTranslatef(-(this->x + this->width * 0.5f), -this->y, -(this->z + this->height * 0.5f));
	
	this->wheels[1].render();

	glPopMatrix();

	this->wheels[2].render();
	this->wheels[3].render();

	renderChassis();
	renderSpoiler();
	renderCabin();
	renderExhaustPipe();
}

void Rover::setRotation(float angle) {
	this->angle = angle;
}

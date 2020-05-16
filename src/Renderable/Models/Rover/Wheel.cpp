#include "Wheel.h"
#include <math.h>

void Wheel::render() {
	float depth = width * 0.5f;

	// Left side
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.51f, 0.51f, 0.51f);

	glVertex3f(this->x, this->y, this->z);
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625) {
		// Width and height are both the same
		float z = this->width * cos(a);
		float y = this->width * sin(a);
		glVertex3f(this->x - depth * 0.5f, this->y + y, this->z + z);
	}
	glEnd();

	// Right side
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.51f, 0.51f, 0.51f);

	glVertex3f(this->x + depth * 0.5f, this->y + this->width, this->z);
	int i = 0;
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625, i++) {
		float z = this->width * sin(a);
		float y = this->width * cos(a);
		if (i % 2 == 0) {
			glVertex3f(this->x - depth * 0.5f, this->y + y, this->z + z);
		} else {
			glVertex3f(this->x + depth * 0.5f, this->y + y, this->z + z);
		}
	}

	glEnd();

	// Tire
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.51f, 0.51f, 0.51f);

	glVertex3f(this->x, this->y, this->z);
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625) {
		// Width and height are both the same
		float z = this->width * cos(a);
		float y = this->width * sin(a);
		glVertex3f(this->x + depth * 0.5f, this->y + y, this->z + z);
	}

	glEnd();

	// Small red circle in the center - right
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.51f, 0, 0);

	glVertex3f(this->x + depth * 0.5f, this->y, this->z);
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625) {
		// Width and height are both the same
		float z = this->width * cos(a) * 0.15f;
		float y = this->width * sin(a) * 0.15f;
		glVertex3f(this->x + depth * 0.5f, this->y + y, this->z + z);
	}

	glEnd();

	// Small red circle in the center - left
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.51f, 0, 0);

	glVertex3f(this->x - depth * 0.5f, this->y, this->z);
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625) {
		// Width and height are both the same
		float z = this->width * cos(a) * 0.15f;
		float y = this->width * sin(a) * 0.15f;
		glVertex3f(this->x - depth * 0.5f, this->y + y, this->z + z);
	}

	glEnd();
}

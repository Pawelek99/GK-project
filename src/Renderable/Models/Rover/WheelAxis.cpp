#include "WheelAxis.h"
#include <windows.h>
#include <gl\gl.h>
#include <math.h>

void WheelAxis::render() {
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.8f, 0.8f, 0.8f);

	glVertex3f(this->x + this->width * 0.5f, this->y, this->z + this->height);
	int i = 0;
	for (float a = 0.0f; a <= PI * 2.1f; a += PI * 0.0625, i++) {
		float z = this->height * cos(a);
		float y = this->height * sin(a);
		if (i % 2 == 0) {
			glVertex3f(this->x - this->width * 0.5f, this->y + y, this->z + z);
		} else {
			glVertex3f(this->x + this->width * 0.5f, this->y + y, this->z + z);
		}
	}

	glEnd();
}

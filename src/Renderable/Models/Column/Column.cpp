#include "Column.h"
#include <math.h>

void Column::render() {
	glColor3f(0.15f, 0.14f, 0.19f);

	// Bottom
	glBegin(GL_TRIANGLE_FAN);

	for (float angle = 0; angle < PI * 2.1f; angle += PI * 0.0625) {
		float x = this->width * cos(angle);
		float z = this->width * sin(angle);
		glVertex3f(this->x + x, this->y, this->z + z);
	}

	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(this->x, this->y, this->z);
	int i = 0;
	for (float angle = 0; angle < PI * 2.1f; angle += PI * 0.0625, i++) {
		if (i % 2 == 0) {
			// Drawing point on the wider bottom side
			float x = this->width * cos(angle);
			float z = this->width * sin(angle);
			glVertex3f(this->x + x, this->y, this->z + z);
		} else {
			// Drawing point on the thinner top side
			float x = this->width * cos(angle) * 0.75f;
			float z = this->width * sin(angle) * 0.75f;
			glVertex3f(this->x + x, this->y + this->height, this->z + z);
		}
	}

	glEnd();

	//Top
	glBegin(GL_TRIANGLE_FAN);

	for (float angle = 0; angle < PI * 2.1f; angle += PI * 0.0625) {
		float x = this->width * cos(angle) * 0.75f;
		float z = this->width * sin(angle) * 0.75f;
		glVertex3f(this->x + x, this->y + this->height, this->z + z);
	}

	glEnd();
}

#include "Ground.h"
#include "PerlinNoise.h"

void Ground::render() {
	glColor3f(0.8f, 0.4f, 0.2f);
	glBegin(GL_TRIANGLE_STRIP);

	for (int z = -this->height; z < this->height; z += 20) {
		for (int x = -this->width; x < this->width; x += 20) {
			glVertex3f(this->x + x, -100 + 500 * ValueNoise_2D(x / 5, z / 5) + this->y, this->z + z);
			glVertex3f(this->x + x, -100 + 500 * ValueNoise_2D(x / 5, z / 5 + 4) + this->y, this->z + z + 20);
		}
	}
	glEnd();
}

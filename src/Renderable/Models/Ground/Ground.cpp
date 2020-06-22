#include "Ground.h"
#include "PerlinNoise.h"

void Ground::setSize(GLfloat width, GLfloat height) {
	this->width = width;
	this->height = height;

	this->groundData = new Vector*[this->width * 2 / 20];
	for (int x = 0; x < 2 * this->width / 20; x++) {
		this->groundData[x] = new Vector[this->height * 2 / 20];
	}

	for (int z = 0; z < 2 * this->height / 20; z++) {
		for (int x = 0; x < 2 * this->width / 20; x++) {
			this->groundData[x][z] = { ValueNoise_2D((x * 20 - this->width) / 5, (z * 20 - this->height) / 5), ValueNoise_2D((x * 20 - this->width) / 5, (z * 20 - this->height) / 5 + 4) };
		}
	}
}

void Ground::render() {
	glColor3f(0.8f, 0.4f, 0.2f);
	glBegin(GL_TRIANGLE_STRIP);

	for (int z = -this->height; z < this->height; z += 20) {
		for (int x = -this->width; x < this->width; x += 20) {
			Vector value = this->groundData[(int)(x + this->width) / 20][(int)(z + this->height) / 20];
			glVertex3f(this->x + x, -100 + 500 * value.x + this->y, this->z + z);
			glVertex3f(this->x + x, -100 + 500 * value.y + this->y, this->z + z + 20);
		}
	}
	glEnd();
}

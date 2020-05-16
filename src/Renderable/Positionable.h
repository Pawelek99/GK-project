#pragma once
#include <windows.h>
#include <gl\gl.h>

class Positionable {
public:
	void setPosition(GLfloat x, GLfloat y, GLfloat z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

protected:
	GLfloat x;
	GLfloat y;
	GLfloat z;
};
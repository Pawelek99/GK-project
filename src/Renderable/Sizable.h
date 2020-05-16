#pragma once
#include <windows.h>
#include <gl\gl.h>

class Sizeable {
public:
	void setSize(GLfloat width, GLfloat height) {
		this->width = width;
		this->height = height;
	}

protected:
	GLfloat width;
	GLfloat height;
};
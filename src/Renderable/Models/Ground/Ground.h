#pragma once
#include "../../IRenderable.h"
#include "../../Positionable.h"
#include "../../Sizable.h"

struct Vector {
	double x, y;
};

class Ground : public IRenderable, public Positionable, public Sizeable {
public:
	void setSize(GLfloat width, GLfloat height);
	void render() override;

private:
	Vector** groundData;
};
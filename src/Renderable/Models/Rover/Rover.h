#pragma once
#include "../../IRenderable.h"
#include "../../Positionable.h"
#include "WheelAxis.h"
#include "Wheel.h"

class Rover : public IRenderable, public Positionable, public Sizeable {
public:
	Rover();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void render() override;
	void renderChassis();
	void renderSpoiler();
	void renderCabin();
	void renderExhaustPipe();

private:
	const float PI = 3.14f;
	WheelAxis wheelAxis[2];
	Wheel wheels[4];
};
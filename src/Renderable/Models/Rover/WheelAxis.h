#pragma once
#include "../../IRenderable.h"
#include "../../Positionable.h"
#include "../../Sizable.h"
#include "Wheel.h"

class WheelAxis : public IRenderable, public Positionable, public Sizeable {
public:
	void render() override;

private:
	const float PI = 3.14f;
};
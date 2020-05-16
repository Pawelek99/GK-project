#pragma once
#include "../IRenderable.h"
#include "../Positionable.h"
#include "../Sizable.h"

class Cuboid : public IRenderable, public Positionable, public Sizeable {
public:
	void render() override;
};
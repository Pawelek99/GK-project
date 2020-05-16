#pragma once
#include "../../IRenderable.h"
#include "../../Positionable.h"
#include "../../Sizable.h"

class Ground : public IRenderable, public Positionable, public Sizeable {
public:
	void render() override;
};
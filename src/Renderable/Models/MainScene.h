#pragma once
#include "../IRenderable.h"
#include "Rover/Rover.h"
#include "Ground/Ground.h"
#include "Column/Column.h"
#include "Cuboid.h"
#include <windows.h>

class MainScene : public IRenderable {
public:
	MainScene();
	void render() override;
	bool handleInput(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	Rover rover;
	Ground ground;
	Column columns[4];
	Cuboid cuboid;
};

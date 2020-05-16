#include "./MainScene.h"

MainScene::MainScene() {
	rover.setPosition(0, 15, 0);
	rover.setSize(50, 30);

	ground.setPosition(0, -20, 0);
	ground.setSize(300, 300);

	columns[0].setPosition(40, -50, -40);
	columns[1].setPosition(-40, -50, 40);
	columns[2].setPosition(40, -50, 40);
	columns[3].setPosition(-40, -50, -40);

	for (auto& c : columns) {
		c.setSize(10, 50);
	}

	cuboid.setPosition(0, 0, 0);
	cuboid.setSize(60, 4);
}

void MainScene::render() {
	rover.render();
	ground.render();

	for (auto& c : columns) {
		c.render();
	}

	cuboid.render();
}

bool MainScene::handleInput(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_NUMPAD8:
			break;
		case VK_NUMPAD2:
			break;
		case VK_NUMPAD4:
			break;
		case VK_NUMPAD6:
			break;
		default:
			return false;
		}

		InvalidateRect(hWnd, NULL, FALSE);
		return true;
	}
	return false;
}

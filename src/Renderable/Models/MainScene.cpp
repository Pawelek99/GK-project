#include "./MainScene.h"
#include <math.h>

MainScene::MainScene() {
	rover.setPosition(0, 15, 0);
	rover.setSize(50, 30);

	ground.setPosition(0, -20, 0);
	ground.setSize(3000, 3000);

	columns[0].setPosition(40, -50, -40);
	columns[1].setPosition(-40, -50, 40);
	columns[2].setPosition(40, -50, 40);
	columns[3].setPosition(-40, -50, -40);

	for (auto& c : columns) {
		c.setSize(10, 50);
	}

	cuboid.setPosition(0, 0, 0);
	cuboid.setSize(60, 4);

	this->pos[0] = this->pos[2] = 0.0f;
	this->pos[1] = -20;
}

void MainScene::render() {
	this->speed += this->force * this->verticalDirection;

	this->pos[2] += this->speed * sinf((this->rotation + 90) / 180.0f * 3.141592);
	this->pos[0] += this->speed * cosf((this->rotation + 90) / 180.0f * 3.141592);
	this->speed *= this->friction;
	
	this->rotation += 0.25f * this->speed * this->horizontalDirection;

	rover.setRotation(this->horizontalDirection);

	ground.setPosition(this->pos[0], this->pos[1], this->pos[2]);

	columns[0].setPosition(this->pos[0] + 40, this->pos[1] + -50 + 20, this->pos[2] + -40);
	columns[1].setPosition(this->pos[0] + -40, this->pos[1] + -50 + 20, this->pos[2] + 40);
	columns[2].setPosition(this->pos[0] + 40, this->pos[1] + -50 + 20, this->pos[2] + 40);
	columns[3].setPosition(this->pos[0] + -40, this->pos[1] + -50 + 20, this->pos[2] + -40);

	cuboid.setPosition(this->pos[0], this->pos[1] + 20, this->pos[2]);

	rover.render();

	glPushMatrix();
	glTranslatef(-25 * sinf((this->rotation + 90) / 180.0f * 3.141592), 0, 0);
	glRotatef(this->rotation, 0, 1, 0);
	glTranslatef(25 * sinf((this->rotation + 90) / 180.0f * 3.141592), 0, 0);

	ground.render();

	for (auto& c : columns) {
		c.render();
	}

	cuboid.render();

	glPopMatrix();
}

bool MainScene::handleInput(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_NUMPAD8:
			this->verticalDirection = -1;
			break;
		case VK_NUMPAD2:
			this->verticalDirection = 1;
			break;
		case VK_NUMPAD4:
			this->horizontalDirection = 1;
			break;
		case VK_NUMPAD6:
			this->horizontalDirection = -1;
			break;
		default:
			return false;
		}

		InvalidateRect(hWnd, NULL, FALSE);
		return true;

	case WM_KEYUP:
		switch (wParam) {
		case VK_NUMPAD8:
		case VK_NUMPAD2:
			this->verticalDirection = 0;
			break;
		case VK_NUMPAD4:
		case VK_NUMPAD6:
			this->horizontalDirection = 0;
			break;
		}

		InvalidateRect(hWnd, NULL, FALSE);
		return true;
	}
	return false;
}

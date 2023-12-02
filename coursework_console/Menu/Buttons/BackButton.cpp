#include "BackButton.h"

BackButton::BackButton(Menu* previousMenu) : Button("�����") {
	this->previousMenu = previousMenu;
}

BackButton::BackButton(const std::string& text, Menu* previousMenu) : Button(text) {
	this->previousMenu = previousMenu;
}

void BackButton::execute() {
	previousMenu->show();
}
#include "MenuBuilder.h"

MenuBuilder::MenuBuilder(const std::string& menuName) {
	currentMenu = new Menu(menuName);
}

void MenuBuilder::addButton(Button* button) {
	currentMenu->addButton(button);
}

void MenuBuilder::removeButton(Button* button) {
	currentMenu->removeButton(button);
}

void MenuBuilder::removeLastButton() {
	currentMenu->removeLastButton();
}

Menu* MenuBuilder::getMenu() {
	return currentMenu;
}
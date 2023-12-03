#include "OpenMenuButton.h"

OpenMenuButton::OpenMenuButton(const std::string& text, Menu* menu) : Button(text) 
{
	this->menu = menu;
}

void OpenMenuButton::setMenu(Menu* menu)
{
	this->menu = menu;
}

void OpenMenuButton::execute() {
	menu->show();
}
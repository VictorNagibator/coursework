#pragma once
#include "Menu.h"

class MenuBuilder
{
public:
	MenuBuilder(const std::string& menuName) : currentMenu(menuName) {};
	~MenuBuilder() = default;

	void addButton(Button* button);
	void removeButton(Button* button);
	void removeLastButton();
	Menu getMenu();
protected:
	Menu currentMenu;
};
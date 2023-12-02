#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "../Buttons/Button.h"

class Menu
{
public:
	Menu() = default;
	Menu(const std::string& name);
	Menu(const std::string& name, std::vector<Button*> buttons);
	~Menu() = default;

	void addButton(Button* button);
	void removeButton(Button* button);
	void removeLastButton();
	void back();
	virtual void show();
private:
	std::string name;
	std::vector<Button*> buttons;
	Menu* previousMenu;

	void chooseButton();
	void setPreviousMenu(Menu* previousMenu);
};
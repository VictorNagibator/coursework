#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Buttons/Button.h"

class Menu
{
public:
	Menu(const std::string& name);
	Menu(const std::string& name, std::vector<Button*> buttons);
	~Menu() = default;

	void addButton(Button* button);
	void removeButton(Button* button);
	void removeLastButton();
	void show();
private:
	std::string name;
	std::vector<Button*> buttons;

	void chooseButton();
};
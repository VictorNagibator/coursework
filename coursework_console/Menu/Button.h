#pragma once
#include <iostream>
#include "MenuItem.h"

class Button : public MenuItem
{
public:
	Button(const std::string& name, MenuItem* action);
	void execute();
	std::string getText();
protected:
	std::string text;
	MenuItem* action;
};
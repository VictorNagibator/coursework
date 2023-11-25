#pragma once
#include <iostream>
#include "../MenuItem.h"

class Button abstract : public MenuItem
{
public:
	Button(const std::string& text);

	std::string getText();
	void execute() override = 0;
protected:
	std::string text;
};
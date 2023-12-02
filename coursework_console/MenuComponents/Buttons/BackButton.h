#pragma once
#include "Button.h"
#include "../Menus/Menu.h"

class BackButton : public Button
{
public:
	BackButton(Menu* previousMenu);
	BackButton(const std::string& text, Menu* previousMenu);

	void execute() override;
private:
	Menu* previousMenu;
};
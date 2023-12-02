#pragma once
#include "Button.h"
#include "../Menu.h"

class OpenMenuButton : public Button
{
public:
	OpenMenuButton(const std::string& text, Menu* menu);
	void execute() override;
private:
	Menu* menu;
};
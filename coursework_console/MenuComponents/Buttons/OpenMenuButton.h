#pragma once
#include "Button.h"
#include "../Menus/Menu.h"

class OpenMenuButton : public Button
{
public:
	OpenMenuButton(const std::string& text, Menu* menu);
	~OpenMenuButton() = default;

	void setMenu(Menu* menu);

	void execute() override;
private:
	Menu* menu;
};
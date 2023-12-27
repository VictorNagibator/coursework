#pragma once
#include "Button.h"
#include "../Menus/ChangeOrderMenu.h"

class ChooseOrderButton : public Button
{
public:
	ChooseOrderButton(const std::string& title, ChangeOrderMenu* menu);
	void execute() override;
private:
	ChangeOrderMenu* menu;
};
#pragma once
#include "Button.h"
#include "../../OrderComponents/Order.h"
#include "../../DataManagers/ChangableObject.h"
#include "../Menus/ChangeOrderMenu.h"

class ChangeOrderButton : public Button
{
public:
	ChangeOrderButton(const std::string& title, ChangeOrderMenu* menu, ChangableObject changableObject);

	void setPreviousMenu(ChangeOrderMenu* menu);
	void setChangableObject(ChangableObject changableObject);
	void execute() override;
protected:
	ChangableObject changableObject;
	ChangeOrderMenu* parentMenu;
};
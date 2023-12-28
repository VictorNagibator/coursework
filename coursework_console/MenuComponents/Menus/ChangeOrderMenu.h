#pragma once
#include "Menu.h"
#include "../../OrderComponents/Order.h"

class ChangeOrderMenu : public Menu
{
public:
	ChangeOrderMenu(const std::string& title);
	ChangeOrderMenu(const std::string& title, int idOfOrder);

	void show() override;

	int getID() const;
	void setID(int id);
private:
	int idOfChangableOrder;
};
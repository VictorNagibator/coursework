#pragma once
#include "Menu.h"
#include "../../OrderComponents/Order.h"

class ChangeOrderMenu : public Menu
{
public:
	ChangeOrderMenu(const std::string& title);
	ChangeOrderMenu(const std::string& title, int idOfOrder);
	ChangeOrderMenu(const std::string& title, const Order& order);

	void show() override;

	const Order& getOrder() const;
	void setOrder(const Order& order);
private:
	Order changableOrder;
};
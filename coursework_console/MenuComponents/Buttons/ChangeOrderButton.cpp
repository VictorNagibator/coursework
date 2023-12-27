#include <conio.h>
#include "ChangeOrderButton.h"

ChangeOrderButton::ChangeOrderButton(const std::string& title, const Order& order, ChangableObject changableObject) : Button(title)
{
	this->changableOrder = order;
	this->changableObject = changableObject;
}

void ChangeOrderButton::setOrder(const Order& order)
{
	this->changableOrder = order;
}

void ChangeOrderButton::setChangableObject(ChangableObject changableObject)
{
	this->changableObject = changableObject;
}

void ChangeOrderButton::execute()
{
	std::cout << "Еще не реализовано" << std::endl;
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}
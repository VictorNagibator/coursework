#include <iostream>
#include <windows.h>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Laptop laptop;
	laptop.input();
	std::cout << laptop << "\n";

	Order test = Order(laptop);
	std::cout << test << "\n";
}
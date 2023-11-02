#include <iostream>
#include <windows.h>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SSD test;
	test.input();

	std::cout << test;

}
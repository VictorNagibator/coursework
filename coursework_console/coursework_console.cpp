#include <iostream>
#include <windows.h>
#include "Order.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Laptop test;
	test.input();
	std::cout << test;
	test.boostCPU();
	std::cout << test;
	
	Order test2 = Order(test);
	std::cout << test2;
	Order test3 = Order(test);
	std::cout << test3;

	return 0;
}
#include <iostream>
#include <fstream>
#include <windows.h>
#include "OrderComponents/Order.h"
#include "Menu/StandartMenuDirector.h"
#include "Menu/Menu.h"
#include "Menu/MenuBuilder.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MenuBuilder builder = MenuBuilder("Главное меню");
	StandartMenuDirector dir;
	dir.buildMenu(builder);
	Menu menu = builder.getMenu();
	
	//menu.show();

	std::vector<Laptop> laptops = { Laptop(), Laptop() };
	nlohmann::json j;

	for (const auto& laptop : laptops) {
		j.push_back(laptop.toJSON());
	}

	std::ofstream file("../orders.json");
	file << std::setw(4) << j << std::endl;
	file.close();

	std::ifstream file("../orders.json");
	nlohmann::json j2;
	file >> j2;

	return 0;
}
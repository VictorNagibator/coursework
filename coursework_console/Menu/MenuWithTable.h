#pragma once
#include "Menu.h"
#include "Table.h"

class MenuWithTable : public Menu
{
public:
	MenuWithTable(const std::string& text);

	void show() override;
};
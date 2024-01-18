#pragma once
#include "Menu.h"
#include "../Table.h"

class MenuWithTable : public Menu
{
public:
	MenuWithTable(const std::string& text);
	~MenuWithTable() = default;

	void show() override;
};
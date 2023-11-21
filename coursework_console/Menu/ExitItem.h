#pragma once
#include "MenuItem.h"

class ExitItem : public MenuItem
{
public:
	ExitItem() = default;
	void execute() override;
};
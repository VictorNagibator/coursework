#pragma once
#include "MenuDirector.h"

class StandartMenuDirector : public MenuDirector
{
public:
	void buildMenu(MenuBuilder& builder) override;
};
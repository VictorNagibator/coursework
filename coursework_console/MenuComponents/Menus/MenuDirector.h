#pragma once
#include "MenuBuilder.h"

class MenuDirector abstract
{
public:
	virtual void buildMenu(MenuBuilder& builder) = 0;
};
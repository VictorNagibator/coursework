#pragma once
#include <iostream>

class MenuItem abstract
{
public:
	virtual void execute() = 0;
};
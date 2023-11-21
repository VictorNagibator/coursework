#pragma once
#include <iostream>
#include <functional>

class MenuItem abstract
{
public:
	virtual void execute() = 0;
};
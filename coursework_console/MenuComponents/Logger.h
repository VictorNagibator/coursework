#pragma once
#include "OrderOperation.h"

class Logger
{
public:
	static void log(int IDOfOrder, OrderOperation operation);
};
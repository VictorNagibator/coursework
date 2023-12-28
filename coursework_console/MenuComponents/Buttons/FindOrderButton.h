#pragma once
#include "Button.h"

class FindOrderButton : public Button
{
public:
	FindOrderButton(const std::string& title);

	void execute() override;
};
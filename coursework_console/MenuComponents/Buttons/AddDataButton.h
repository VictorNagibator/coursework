#pragma once
#include "Button.h"

class AddDataButton : public Button
{
public:
	AddDataButton(const std::string& title);
	~AddDataButton() = default;
	void execute() override;
};

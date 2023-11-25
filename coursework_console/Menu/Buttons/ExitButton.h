#pragma once
#include "Button.h"

class ExitButton : public Button
{
public:
	ExitButton();
	ExitButton(const std::string& text);
	~ExitButton() = default;

	void execute() override;
};
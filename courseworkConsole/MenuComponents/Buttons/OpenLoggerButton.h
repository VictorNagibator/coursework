#pragma once
#include "Button.h"

class OpenLoggerButton : public Button
{
public:
	OpenLoggerButton(const std::string& title);
	void execute() override;
};
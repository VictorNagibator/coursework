#pragma once
#include "Button.h"

class ChooseFileButton : public Button
{
public:
	ChooseFileButton();
	ChooseFileButton(const std::string& text);

	void execute() override;
};
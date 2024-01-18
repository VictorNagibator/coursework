#pragma once
#include "Button.h"

class ChooseFileButton : public Button
{
public:
	ChooseFileButton();
	ChooseFileButton(const std::string& text);
	~ChooseFileButton() = default;

	void execute() override;
};
#pragma once
#include "Button.h"
class PlayGameButton : public Button
{
public:
	PlayGameButton(const std::string& text);

	void execute() override;
};
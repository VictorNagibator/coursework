#pragma once
#include "ChangeOrderButton.h"

class BoostComponentButton : public ChangeOrderButton
{
public:
	BoostComponentButton(const std::string& title, ChangeOrderMenu* menu, ChangableObject changableObject);

	void execute() override;
};
﻿#pragma once
#include "Button.h"
#include "../Table.h"

class ShowTableButton : public Button
{
public:
	ShowTableButton(const std::string& text);
	~ShowTableButton() = default;

	void execute() override;
};

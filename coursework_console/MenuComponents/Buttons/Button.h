#pragma once
#include <iostream>

class Button
{
public:
	Button(const std::string& text);
	virtual ~Button() = default;

	std::string getText();
	virtual void execute() = 0;
protected:
	std::string text;
};
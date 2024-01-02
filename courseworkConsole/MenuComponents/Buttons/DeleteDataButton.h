#pragma once
#include "Button.h"

class DeleteDataButton : public Button
{
public:
	DeleteDataButton(const std::string& title);
	~DeleteDataButton() = default;
	void execute() override;
private:
	bool checkArguments(int id);
};
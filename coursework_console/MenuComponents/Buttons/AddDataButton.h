#pragma once
#include <nlohmann/json.hpp>
#include "Button.h"

using json = nlohmann::json;

class AddDataButton : public Button
{
public:
	AddDataButton(const std::string& title);
	void execute() override;
private:
	json data;

	void loadJSON();
	void saveJSON();
};

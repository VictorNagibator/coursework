#pragma once
#include "Button.h"
#include "../../OrderComponents/Order.h"

enum class ChangableObject
{
	Status,
	AdditionalInfo,
	LaptopName,
	LaptopCPU,
	LaptopGPU,
	LaptopRAM,
	LaptopStorage,
	LaptopDisplay,
	LaptopMotherboard
};

class ChangeOrderButton : public Button
{
public:
	ChangeOrderButton(const std::string& title, const Order& order, ChangableObject changableObject);

	void setOrder(const Order& order);
	void setChangableObject(ChangableObject changableObject);
	void execute() override;
private:
	Order changableOrder;
	ChangableObject changableObject;
};
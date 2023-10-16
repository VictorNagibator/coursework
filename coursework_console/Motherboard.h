#pragma once
#include "RAM.h"

class Motherboard
{
public:
	Motherboard();
	Motherboard(std::string name);
	Motherboard(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
	~Motherboard();

	void operator=(Motherboard other);
	friend std::ostream& operator << (std::ostream& out, const Motherboard& motherboard);

	std::string GetName() const;
	std::string GetSocket() const;
	std::string GetChipset() const;
	RAMType GetSupportedRAMType() const;
	void Input();
private:
	std::string name;
	std::string socket;
	std::string chipset;
	RAMType supportedRAMType = DDR;

	bool CheckArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
	void SetArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
};
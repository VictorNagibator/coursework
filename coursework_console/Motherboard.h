#pragma once
#include <iostream>
#include <string>
#include "RAMType.h"

class Motherboard
{
public:
	Motherboard() = default;
	Motherboard(std::string name);
	Motherboard(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
	~Motherboard() = default;

	void operator=(Motherboard other);
	friend std::ostream& operator << (std::ostream& out, const Motherboard& motherboard);

	std::string getName() const;
	std::string getSocket() const;
	std::string getChipset() const;
	RAMType getSupportedRAMType() const;
	void input();
private:
	std::string name;
	std::string socket;
	std::string chipset;
	RAMType supportedRAMType = DDR;

	bool checkArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
	void setArguments(std::string name, std::string socket, std::string chipset, RAMType supportedRAMType);
};
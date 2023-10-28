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
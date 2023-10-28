#pragma once
#include "CPU.h"
#include "Display.h"
#include "GPU.h"
#include "Motherboard.h"
#include "RAM.h"

class Laptop
{
public:
	Laptop();
	Laptop(std::string name);
	Laptop(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display);
	~Laptop();

	void operator=(Laptop other);
	friend std::ostream& operator << (std::ostream& out, const Laptop& laptop);

	std::string getName() const;
	CPU getCPU() const;
	GPU getGPU() const;
	RAM getRAM() const;
	Motherboard getMotherboard() const;
	Display getDisplay() const;
	void setCPU(CPU cpu);
	void setGPU(GPU gpu);
	void setRAM(RAM ram);
	void setMotherboard(Motherboard motherboard);
	void setDisplay(Display display);
	void input();
	void boostCPU();
	void boostRAM();
private:
	std::string name;
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard motherboard;
	Display display;

	bool checkArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display);
	void setArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display);
};
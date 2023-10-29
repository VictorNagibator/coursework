#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include "CPU.h"
#include "Display.h"
#include "GPU.h"
#include "Motherboard.h"
#include "RAM.h"
#include "HDD.h"
#include "SSD.h"

class Laptop
{
public:
	Laptop() = default;
	Laptop(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage *dataStorage);
	~Laptop() = default;

	void operator=(Laptop other);
	friend std::ostream& operator << (std::ostream& out, const Laptop& laptop);

	std::string getName() const;
	CPU getCPU() const;
	GPU getGPU() const;
	RAM getRAM() const;
	Motherboard getMotherboard() const;
	Display getDisplay() const;
	DataStorage *getDataStorage() const;
	void setCPU(CPU cpu);
	void setGPU(GPU gpu);
	void setRAM(RAM ram);
	void setMotherboard(Motherboard motherboard);
	void setDisplay(Display display);
	void setDataStorage(DataStorage* dataStorage);
	void input();
	void boostCPU();
	void boostRAM();
private:
	std::string name;
	CPU cpu = CPU();
	GPU gpu = GPU();
	RAM ram = RAM();
	Motherboard motherboard = Motherboard();
	Display display = Display();
	DataStorage *dataStorage;

	bool checkArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage);
	void setArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage);
};
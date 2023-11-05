#include "Laptop.h"

void Laptop::operator=(Laptop other) {
	this->modelName = other.getModelName();
	this->cpu = other.getCPU();
	this->gpu = other.getGPU();
	this->motherboard = other.getMotherboard();
	this->ram = other.getRAM();
	this->display = other.getDisplay();
	this->dataStorage = other.getDataStorage();
}

std::ostream& operator << (std::ostream& out, const Laptop& laptop) {
	out << laptop.toString();
	return out;
}

Laptop::Laptop(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage *dataStorage) {
	tryToSetArguments(modelName, cpu, gpu, ram, motherboard, display, dataStorage);
}

std::string Laptop::getModelName() const {
	return modelName;
}

const CPU& Laptop::getCPU() const {
	return cpu;
}

const GPU& Laptop::getGPU() const {
	return gpu;
}

const RAM& Laptop::getRAM() const {
	return ram;
}

const Motherboard& Laptop::getMotherboard() const {
	return motherboard;
}

const Display& Laptop::getDisplay() const {
	return display;
}

DataStorage* Laptop::getDataStorage() const {
	return dataStorage;
}

void Laptop::setModelName(std::string modelName) {
	this->modelName = modelName;
}

void Laptop::setCPU(CPU cpu) {
	if (checkArguments(this->modelName, cpu, this->gpu, this->ram, this->motherboard, this->display, this->dataStorage)) {
		this->cpu = cpu;
	}
	else throw std::invalid_argument("                  !");
}

void Laptop::setGPU(GPU gpu) {
	this->gpu = gpu;
}

void Laptop::setRAM(RAM ram) {
	if (checkArguments(this->modelName, this->cpu, this->gpu, ram, this->motherboard, this->display, this->dataStorage)) {
		this->ram = ram;
	}
	else throw std::invalid_argument("                       !");
}

void Laptop::setMotherboard(Motherboard motherboard) {
	this->motherboard = motherboard;

	//                        ,                            
	if (this->cpu.getSocket() != motherboard.getSocket()) { this->cpu = CPU(); }
	//                                         ,                         ,                                
	if (this->ram.getRAMType() != motherboard.getSupportedRAMType()) { this->ram = RAM(motherboard.getSupportedRAMType()); }
}

void Laptop::setDisplay(Display display) {
	this->display = display;
}

void Laptop::setDataStorage(DataStorage* dataStorage) {
	DataStorage* newDataStorage = dataStorage;
	this->dataStorage = newDataStorage;
}

void Laptop::input() {
	std::cout << "                         : ";
	std::getline(std::cin, modelName);
	std::cout << "\t                          \n";
	cpu.input();
	std::cout << "\t                          \n";
	gpu.input();
	std::cout << "\t                RAM\n";
	ram.input();
	std::cout << "\t                                 \n";
	motherboard.input();
	std::cout << "\t                      \n";
	display.input();
	std::cout << "\t                         \n";
	std::cout << "                      (0 - HDD, 1 - SSD): ";
	int choice;
	do
	{
		std::cin >> choice;
		if (choice != 0 && choice != 1) std::cout << "                    !\n               : ";
	} while (choice != 0 && choice != 1);
	dataStorage = createDataStorage(choice);
	dataStorage->input();
}

void Laptop::boostCPU() {
	if (this->cpu.getFrequency() + this->cpu.tryFreq <= this->cpu.maxFreq) {
		cpu = CPU(this->cpu.getModelName(), this->cpu.getSocket(), this->cpu.getFrequency() + this->cpu.tryFreq, this->cpu.getNumOfCores());
	}
	else if (this->cpu.getFrequency() < this->cpu.maxFreq) {
		cpu = CPU(this->cpu.getModelName(), this->cpu.getSocket(), this->cpu.maxFreq, this->cpu.getNumOfCores());
	}
	else std::cout << "       CPU                  !\n";
}

void Laptop::boostRAM() {
	float maxFreq = this->ram.DDRFreqMax[this->ram.getRAMType()];
	if (this->ram.getFrequency() + this->ram.tryFreq <= maxFreq) {
		ram = RAM(this->ram.getModelName(), this->ram.getRAMType(), this->ram.getFrequency() + this->ram.tryFreq, this->ram.getCapacity());
	}
	else if (this->ram.getFrequency() < maxFreq) {
		ram = RAM(this->ram.getModelName(), this->ram.getRAMType(), maxFreq, this->ram.getCapacity());
	}
	else std::cout << "       RAM                  !\n";
}

std::string Laptop::toString() const {
	std::string name = 
		"               : " + this->modelName + "\n" +
		"CPU: " + this->cpu.toString() + "\n" +
		"GPU: " + this->gpu.toString() + "\n" +
		"RAM: " + this->ram.toString() + "\n" +
		"                 : " + this->motherboard.toString() + "\n" +
		"     : " + this->display.toString() + "\n" +
		this->dataStorage->getComponentName() + ": " + dataStorage->toString() + "\n";
	return name;
}


bool Laptop::checkArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage *dataStorage) {
	return (cpu.getSocket() == motherboard.getSocket()) && (ram.getRAMType() == motherboard.getSupportedRAMType());
}

void Laptop::tryToSetArguments(std::string modelName, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display, DataStorage* dataStorage) {
	if (checkArguments(modelName, cpu, gpu, ram, motherboard, display, dataStorage)) {
		this->modelName = modelName;
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		this->motherboard = motherboard;
		this->display = display;
		this->dataStorage = dataStorage;
	}
	else throw std::invalid_argument("                          !");
}

DataStorage* Laptop::createDataStorage(int choice) {
	DataStorage* dataStorage;
	if (choice == 0) dataStorage = new HDD();
	else dataStorage = new SSD();
	return dataStorage;
}
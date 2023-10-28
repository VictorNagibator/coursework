#include <iostream>
#include <string>
#include "Laptop.h"

void Laptop::operator=(Laptop other) {
	this->name = other.getName();
	this->cpu = other.getCPU();
	this->gpu = other.getGPU();
	this->motherboard = other.getMotherboard();
	this->ram = other.getRAM();
	this->display = other.getDisplay();
}

std::ostream& operator << (std::ostream& out, const Laptop& laptop) {
	out << 
		"�������� ������: " << laptop.name << "\n" <<
		"CPU: " << laptop.cpu << "\n" <<
		"GPU: " << laptop.gpu << "\n" <<
		"RAM: " << laptop.ram << "\n" <<
		"����������� �����: " << laptop.motherboard << "\n" <<
		"�����: " << laptop.display;
	return out;
}

Laptop::Laptop()
{
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	motherboard = Motherboard();
	display = Display();
}

Laptop::Laptop(std::string name) {
	this->name = name;
	cpu = CPU();
	gpu = GPU();
	ram = RAM();
	motherboard = Motherboard();
	display = Display();
}

Laptop::Laptop(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display) {
	setArguments(name, cpu, gpu, ram, motherboard, display);
}

Laptop::~Laptop()
{
}

std::string Laptop::getName() const {
	return name;
}

CPU Laptop::getCPU() const {
	return cpu;
}

GPU Laptop::getGPU() const {
	return gpu;
}

RAM Laptop::getRAM() const {
	return ram;
}

Motherboard Laptop::getMotherboard() const {
	return motherboard;
}

Display Laptop::getDisplay() const {
	return display;
}

void Laptop::setCPU(CPU cpu) {
	if (checkArguments(this->name, cpu, this->gpu, this->ram, this->motherboard, this->display)) {
		this->cpu = cpu;
	}
	else throw std::invalid_argument("������������ �����!");
}

void Laptop::setGPU(GPU gpu) {
	this->gpu = gpu;
}

void Laptop::setRAM(RAM ram) {
	if (checkArguments(this->name, this->cpu, this->gpu, ram, this->motherboard, this->display)) {
		this->ram = ram;
	}
	else throw std::invalid_argument("������������ ��� ������!");
}

void Laptop::setMotherboard(Motherboard motherboard) {
	this->motherboard = motherboard;

	//���� ������ �� ���������, �� ������ ��������� �������
	if (this->cpu.getSocket() != motherboard.getSocket()) { this->cpu = CPU(); }
	//���� �� ��������� ���� ����������� ������, �� ������ ������ �������, � ����� ������ � ����� �� �����
	if (this->ram.getRAMType() != motherboard.getSupportedRAMType()) { this->ram = RAM(motherboard.getSupportedRAMType()); }
}

void Laptop::setDisplay(Display display) {
	this->display = display;
}

void Laptop::input() {
	std::cout << "������� �������� ��������: ";
	std::getline(std::cin, name);
	std::cout << "\t���� ���������� ����������\n";
	cpu.input();
	std::cout << "\t���� ���������� ����������\n";
	gpu.input();
	std::cout << "\t���� ���������� RAM\n";
	ram.input();
	std::cout << "\t���� ���������� ����������� �����\n";
	motherboard.input();
	std::cout << "\t���� ���������� ������\n";
	display.input();
}

void Laptop::boostCPU() {
	if (this->cpu.getFrequency() + this->cpu.tryFreq <= this->cpu.maxFreq) {
		cpu = CPU(this->cpu.getName(), this->cpu.getSocket(), this->cpu.getFrequency() + this->cpu.tryFreq, this->cpu.getNumOfCores());
	}
	else if (this->cpu.getFrequency() < this->cpu.maxFreq) {
		cpu = CPU(this->cpu.getName(), this->cpu.getSocket(), this->cpu.maxFreq, this->cpu.getNumOfCores());
	}
	else std::cout << "������ CPU ������ ����������!\n";
}

void Laptop::boostRAM() {
	float maxFreq = this->ram.DDRFreqMax[this->ram.getRAMType()];
	if (this->ram.getFrequency() + this->ram.tryFreq <= maxFreq) {
		ram = RAM(this->ram.getName(), this->ram.getRAMType(), this->ram.getFrequency() + this->ram.tryFreq, this->ram.getCapacity());
	}
	else if (this->ram.getFrequency() < maxFreq) {
		ram = RAM(this->ram.getName(), this->ram.getRAMType(), maxFreq, this->ram.getCapacity());
	}
	else std::cout << "������ RAM ������ ����������!\n";
}


bool Laptop::checkArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display) {
	return (cpu.getSocket() == motherboard.getSocket()) && (ram.getRAMType() == motherboard.getSupportedRAMType());
}

void Laptop::setArguments(std::string name, CPU cpu, GPU gpu, RAM ram, Motherboard motherboard, Display display) {
	if (checkArguments(name, cpu, gpu, ram, motherboard, display)) {
		this->name = name;
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		this->motherboard = motherboard;
		this->display = display;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}
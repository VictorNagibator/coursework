#include <iostream>
#include <string>
#include "GPU.h"

void GPU::operator=(GPU other) {
	this->name = other.getName();
	this->frequency = other.getFrequency();
	this->vram = other.getVRAM();
}

std::ostream& operator << (std::ostream& out, const GPU& gpu) {
	out << gpu.getName() << ", " << gpu.getFrequency() << " ���, " << gpu.getVRAM() << " ��";
	return out;
}

GPU::GPU()
{

}

GPU::GPU(std::string name)
{
	this->name = name;
}

GPU::GPU(std::string name, float frequency, int vram)
{
	setArguments(name, frequency, vram);
}

GPU::~GPU()
{
}

std::string GPU::getName() const {
	return name;
}

float GPU::getFrequency() const {
	return frequency;
}

int GPU::getVRAM() const {
	return vram;
}

void GPU::input() {
	std::string name;
	float frequency;
	int vram;

	std::cout << "������� �������� ����������: ";
	std::getline(std::cin, name);
	std::cout << "������� �������� ������� ������������ ���������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ����� ����������� (� ��): ";
	std::cin >> vram;
	while (getchar() != '\n');
	
	setArguments(name, frequency, vram);
}


bool GPU::checkArguments(std::string name, float frequency, int vram) {
	return frequency >= 0 && vram >= 0;
}

void GPU::setArguments(std::string name, float frequency, int vram) {
	if (checkArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}
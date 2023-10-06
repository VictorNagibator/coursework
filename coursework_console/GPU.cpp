#include <iostream>
#include <string>
#include "GPU.h"

void GPU::operator=(GPU other) {
	this->name = other.GetName();
	this->frequency = other.GetFrequency();
	this->vram = other.GetVRAM();
}

bool GPU::CheckArguments(std::string name, float frequency, int vram) {
	return frequency >= 0 && vram >= 0;
}

GPU::GPU()
{
	frequency = vram = 0;
}

GPU::GPU(std::string name)
{
	this->name = name;
	frequency = vram = 0;
}

GPU::GPU(std::string name, float frequency, int vram)
{
	if (CheckArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

GPU::~GPU()
{
}

std::string GPU::GetName() const {
	return name;
}

float GPU::GetFrequency() const {
	return frequency;
}

int GPU::GetVRAM() const {
	return vram;
}

void GPU::Input() {
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
	if (CheckArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}
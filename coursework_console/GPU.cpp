#include <iostream>
#include <string>
#include "GPU.h"

void GPU::operator=(GPU other) {
	this->name = other.GetName();
	this->frequency = other.GetFrequency();
	this->vram = other.GetVRAM();
}

std::ostream& operator << (std::ostream& out, const GPU& gpu) {
	out << gpu.GetName() << ", " << gpu.GetFrequency() << " МГц, " << gpu.GetVRAM() << " ГБ";
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
	SetArguments(name, frequency, vram);
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

	std::cout << "Введите название видеокарты: ";
	std::getline(std::cin, name);
	std::cout << "Введите тактовую частоту графического процессора (в МГц): ";
	std::cin >> frequency;
	std::cout << "Введите объем видеопамяти (в ГБ): ";
	std::cin >> vram;
	while (getchar() != '\n');
	
	SetArguments(name, frequency, vram);
}


bool GPU::CheckArguments(std::string name, float frequency, int vram) {
	return frequency >= 0 && vram >= 0;
}

void GPU::SetArguments(std::string name, float frequency, int vram) {
	if (CheckArguments(name, frequency, vram)) {
		this->name = name;
		this->frequency = frequency;
		this->vram = vram;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}
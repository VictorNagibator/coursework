#include <iostream>
#include <string>
#include "Cpu.h"

void CPU::operator=(CPU other) {
	this->name = other.GetName();
	this->socket = other.GetSocket();
	this->frequency = other.GetFrequency();
	this->numOfCores = other.GetNumOfCores();
}

std::ostream& operator << (std::ostream& out, const CPU& cpu) {
	out << cpu.GetName() << ", " << cpu.GetSocket() << ", " << cpu.GetFrequency() << " ���, " << cpu.GetNumOfCores() << "-�������";
	return out;
}

CPU::CPU()
{

}

CPU::CPU(std::string name)
{
	this->name = name;
}

CPU::CPU(std::string name, std::string socket, float frequency, int numOfCores)
{
	SetArguments(name, socket, frequency, numOfCores);
}

CPU::~CPU()
{
}

std::string CPU::GetName() const {
	return name;
}

std::string CPU::GetSocket() const {
	return socket;
}

float CPU::GetFrequency() const {
	return frequency;
}

int CPU::GetNumOfCores() const {
	return numOfCores;
}

void CPU::Input() {
	std::string name, socket;
	float frequency;
	int numOfCores;

	std::cout << "������� �������� ����������: ";
	std::getline(std::cin, name);
	std::cout << "������� �������� ������ ����������: ";
	std::getline(std::cin, socket);
	std::cout << "������� ��� �������� ������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ���������� ����: ";
	std::cin >> numOfCores;
	while (getchar() != '\n'); //������� �������� ������ ����� cin

	SetArguments(name, socket, frequency, numOfCores);
}


bool CPU::CheckArguments(std::string name, std::string socket, float frequency, int numOfCores) {
	return frequency >= 0 && frequency < maxFreq && numOfCores >= 0;
}

void CPU::SetArguments(std::string name, std::string socket, float frequency, int numOfCores) {
	if (CheckArguments(name, socket, frequency, numOfCores)) {
		this->name = name;
		this->socket = socket;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}
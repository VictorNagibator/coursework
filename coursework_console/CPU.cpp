#include <iostream>
#include <string>
#include "Cpu.h"

void CPU::operator=(CPU other) {
	this->name = other.GetName();
	this->frequency = other.GetFrequency();
	this->numOfCores = other.GetNumOfCores();
	this->socket = other.GetSocket();
}

bool CPU::CheckArguments(std::string name, float frequency, int numOfCores, std::string socket) {
	return frequency >= 0 && frequency < maxFreq && numOfCores >= 0;
}

CPU::CPU()
{
	frequency = numOfCores = 0;
}

CPU::CPU(std::string name)
{
	this->name = name;
	frequency = numOfCores = 0;
}

CPU::CPU(std::string name, float frequency, int numOfCores, std::string socket)
{
	if (CheckArguments(name, frequency, numOfCores, socket)) {
		this->name = name;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
		this->socket = socket;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}

CPU::~CPU()
{
}

std::string CPU::GetName() const {
	return name;
}

float CPU::GetFrequency() const {
	return frequency;
}

int CPU::GetNumOfCores() const {
	return numOfCores;
}

std::string CPU::GetSocket() const {
	return socket;
}

void CPU::Input() {
	std::string name, socket;
	float frequency;
	int numOfCores;

	std::cout << "������� �������� ����������: ";
	std::getline(std::cin, name);
	std::cout << "������� ��� �������� ������� (� ���): ";
	std::cin >> frequency;
	std::cout << "������� ���������� ����: ";
	std::cin >> numOfCores;
	while (getchar() != '\n'); //������� �������� ������ ����� cin
	std::cout << "������� �������� ������ ����������: ";
	std::getline(std::cin, socket);

	if (CheckArguments(name, frequency, numOfCores, socket)) {
		this->name = name;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
		this->socket = socket;
	}
	else throw std::invalid_argument("������������ ������ ������!");
}
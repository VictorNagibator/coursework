#include "Cpu.h"

void CPU::operator=(CPU other) {
	this->name = other.getName();
	this->socket = other.getSocket();
	this->frequency = other.getFrequency();
	this->numOfCores = other.getNumOfCores();
}

std::ostream& operator << (std::ostream& out, const CPU& cpu) {
	out << cpu.getName() << ", " << cpu.getSocket() << ", " << cpu.getFrequency() << " √√ц, " << cpu.getNumOfCores() << "-€дерный";
	return out;
}

CPU::CPU(std::string name) {
	this->name = name;
}

CPU::CPU(std::string name, std::string socket, float frequency, int numOfCores) {
	setArguments(name, socket, frequency, numOfCores);
}

CPU::~CPU() {

}

std::string CPU::getName() const {
	return name;
}

std::string CPU::getSocket() const {
	return socket;
}

float CPU::getFrequency() const {
	return frequency;
}

int CPU::getNumOfCores() const {
	return numOfCores;
}

void CPU::input() {
	std::string name, socket;
	float frequency;
	int numOfCores;

	std::cout << "¬ведите название процессора: ";
	std::getline(std::cin, name);
	std::cout << "¬ведите название сокета процессора: ";
	std::getline(std::cin, socket);
	std::cout << "¬ведите его тактовую частоту (в √√ц): ";
	std::cin >> frequency;
	std::cout << "¬ведите количество €дер: ";
	std::cin >> numOfCores;
	while (getchar() != '\n'); //очистка входного потока после cin

	setArguments(name, socket, frequency, numOfCores);
}


bool CPU::checkArguments(std::string name, std::string socket, float frequency, int numOfCores) {
	return frequency >= 0 && frequency < maxFreq && numOfCores >= 0;
}

void CPU::setArguments(std::string name, std::string socket, float frequency, int numOfCores) {
	if (checkArguments(name, socket, frequency, numOfCores)) {
		this->name = name;
		this->socket = socket;
		this->frequency = frequency;
		this->numOfCores = numOfCores;
	}
	else throw std::invalid_argument("Ќекорректный формат данных!");
}
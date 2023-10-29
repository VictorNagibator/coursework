#pragma once
#include <iostream>
#include <string>

class CPU
{
public:
	CPU() = default;
	CPU(std::string name);
	CPU(std::string name, std::string socket, float frequency, int numOfCores);
	~CPU();

	void operator=(CPU other);
	friend std::ostream& operator << (std::ostream& out, const CPU& cpu);

	std::string getName() const;
	std::string getSocket() const;
	float getFrequency() const;
	int getNumOfCores() const;
	void input();

	const float maxFreq = 9.0; //условная максимальная тактовая частота для процессора
	const double tryFreq = 0.2; //условное повышение частоты для разгона
private:
	std::string name;
	std::string socket;
	float frequency = 0;
	int numOfCores = 0;

	bool checkArguments(std::string name, std::string socket, float frequency, int numOfCores);
	void setArguments(std::string name, std::string socket, float frequency, int numOfCores);
};
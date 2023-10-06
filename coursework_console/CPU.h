#pragma once

class CPU
{
public:
	CPU();
	CPU(std::string name);
	CPU(std::string name, float frequency, int numOfCores, std::string socket);
	~CPU();

	void operator=(CPU other);

	std::string GetName() const;
	float GetFrequency() const;
	int GetNumOfCores() const;
	std::string GetSocket() const;
	void Input();

	const float maxFreq = 9.0; //условная максимальная тактовая частота для процессора
	const float tryFreq = 0.2; //условное повышение частоты для разгона
private:
	std::string name;
	float frequency;
	int numOfCores;
	std::string socket;

	bool CheckArguments(std::string name, float frequency, int numOfCores, std::string socket);
};
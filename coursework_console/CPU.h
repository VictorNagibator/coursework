#pragma once

class CPU
{
public:
	CPU();
	CPU(std::string name);
	CPU(std::string name, std::string socket, float frequency, int numOfCores);
	~CPU();

	void operator=(CPU other);
	friend std::ostream& operator << (std::ostream& out, const CPU& cpu);

	std::string GetName() const;
	std::string GetSocket() const;
	float GetFrequency() const;
	int GetNumOfCores() const;
	void Input();

	const float maxFreq = 9.0; //условная максимальная тактовая частота для процессора
	const float tryFreq = 0.2; //условное повышение частоты для разгона
private:
	std::string name;
	std::string socket;
	float frequency = 0;
	int numOfCores = 0;

	bool CheckArguments(std::string name, std::string socket, float frequency, int numOfCores);
	void SetArguments(std::string name, std::string socket, float frequency, int numOfCores);
};
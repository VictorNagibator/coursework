#pragma once
#include <vector>

enum RAMType { DDR, DDR2, DDR3, DDR4, DDR5 };

std::istream& operator >> (std::istream& in, RAMType& type);
std::ostream& operator << (std::ostream& out, RAMType& type);

class RAM
{
public:
	RAM();
	RAM(std::string name);
	RAM(std::string name, RAMType type, float frequency, int capacity);
	~RAM();

	void operator=(RAM other);
	friend std::ostream& operator << (std::ostream& out, const RAM& ram);

	std::string GetName() const;
	RAMType GetRAMType() const;
	float GetFrequency() const;
	int GetCapacity() const;
	void Input();

	//вектор максимально возможных частот для каждого типа памяти
	const std::vector<int> DDRFreqMax = { 400, 1066, 2400, 3333, 6400 };
	const float tryFreq = 50; //условное повышение частоты для разгона
private:
	std::string name;
	RAMType type = DDR;
	float frequency = 0;
	int capacity = 0;

	bool CheckArguments(std::string name, RAMType type, float frequency, int capacity);
	void SetArguments(std::string name, RAMType type, float frequency, int capacity);
};
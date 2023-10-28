#pragma once
#include <vector>
#include "RAMType.h"

class RAM
{
public:
	RAM();
	RAM(std::string name);
	RAM(RAMType type);
	RAM(std::string name, RAMType type, float frequency, int capacity);
	~RAM();

	void operator=(RAM other);
	friend std::ostream& operator << (std::ostream& out, const RAM& ram);

	std::string getName() const;
	RAMType getRAMType() const;
	float getFrequency() const;
	int getCapacity() const;
	void input();

	//������ ����������� ��������� ������ ��� ������� ���� ������
	const std::vector<int> DDRFreqMax = { 400, 1066, 2400, 3333, 6400 };
	const float tryFreq = 50; //�������� ��������� ������� ��� �������
private:
	std::string name;
	RAMType type = DDR;
	float frequency = 0;
	int capacity = 0;

	bool checkArguments(std::string name, RAMType type, float frequency, int capacity);
	void setArguments(std::string name, RAMType type, float frequency, int capacity);
};
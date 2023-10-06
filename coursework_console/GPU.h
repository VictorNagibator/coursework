#pragma once

class GPU
{
public:
	GPU();
	GPU(std::string name);
	GPU(std::string name, float frequency, int vram);
	~GPU();

	void operator=(GPU other);

	std::string GetName() const;
	float GetFrequency() const;
	int GetVRAM() const;
	void Input();
private:
	std::string name;
	float frequency;
	int vram;

	bool CheckArguments(std::string name, float frequency, int vram);
};
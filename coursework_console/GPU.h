#pragma once

class GPU
{
public:
	GPU();
	GPU(std::string name);
	GPU(std::string name, float frequency, int vram);
	~GPU();

	void operator=(GPU other);
	friend std::ostream& operator << (std::ostream& out, const GPU& gpu);

	std::string GetName() const;
	float GetFrequency() const;
	int GetVRAM() const;
	void Input();
private:
	std::string name;
	float frequency = 0;
	int vram = 0;

	bool CheckArguments(std::string name, float frequency, int vram);
	void SetArguments(std::string name, float frequency, int vram);
};
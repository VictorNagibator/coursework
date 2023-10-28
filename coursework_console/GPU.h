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

	std::string getName() const;
	float getFrequency() const;
	int getVRAM() const;
	void input();
private:
	std::string name;
	float frequency = 0;
	int vram = 0;

	bool checkArguments(std::string name, float frequency, int vram);
	void setArguments(std::string name, float frequency, int vram);
};
#pragma once
#include <iostream>

class Display
{
public:
	Display() = default;
	Display(int width, int height);
	Display(int width, int height, int refreshRate);
	~Display();

	void operator=(Display other);
	friend std::ostream& operator << (std::ostream& out, const Display& display);

	int getWidth() const;
	int getHeight() const;
	int getRefreshRate() const;
	void input();
private:
	int width = 0, height = 0, refreshRate = 0;

	bool checkArguments(int width, int height, int refreshRate);
	void setArguments(int width, int height, int refreshRate);
};
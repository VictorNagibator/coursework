#pragma once
class Display
{
public:
	Display();
	Display(int width, int height);
	Display(int width, int height, int refreshRate);
	~Display();

	void operator=(Display other);
	friend std::ostream& operator << (std::ostream& out, const Display& display);

	int GetWidth() const;
	int GetHeight() const;
	int GetRefreshRate() const;
	void Input();
private:
	int width = 0, height = 0, refreshRate = 0;

	bool CheckArguments(int width, int height, int refreshRate);
	void SetArguments(int width, int height, int refreshRate);
};
#include <iostream>
#include "Display.h"

void Display::operator=(Display other) {
	this->width = other.GetWidth();
	this->height = other.GetHeight();
	this->refreshRate = other.GetRefreshRate();
}

std::ostream& operator << (std::ostream& out, const Display& display) {
	out << display.GetWidth() << "x" << display.GetHeight() << ", " << display.GetRefreshRate() << " Гц";
	return out;
}

Display::Display()
{

}

Display::Display(int width, int height)
{
	SetArguments(width, height, 0);
}

Display::Display(int width, int height, int refreshRate)
{
	SetArguments(width, height, refreshRate);
}

Display::~Display()
{
}

int Display::GetWidth() const {
	return width;
}

int Display::GetHeight() const {
	return height;
}

int Display::GetRefreshRate() const {
	return refreshRate;
}

void Display::Input() {
	int width, height, refreshRate;

	std::cout << "Введите ширину и высоту экрана (в пикселях): ";
	std::cin >> width >> height;
	std::cout << "Введите частоту обновления экрана (в Гц): ";
	std::cin >> refreshRate;
	while (getchar() != '\n');
	
	SetArguments(width, height, refreshRate);
}


bool Display::CheckArguments(int width, int height, int refreshRate) {
	return width >= 0 && height >= 0 && refreshRate >= 0;
}

void Display::SetArguments(int width, int height, int refreshRate) {
	if (CheckArguments(width, height, refreshRate)) {
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}
#include <iostream>
#include "Display.h"

void Display::operator=(Display other) {
	this->width = other.getWidth();
	this->height = other.getHeight();
	this->refreshRate = other.getRefreshRate();
}

std::ostream& operator << (std::ostream& out, const Display& display) {
	out << display.getWidth() << "x" << display.getHeight() << ", " << display.getRefreshRate() << " Гц";
	return out;
}

Display::Display()
{

}

Display::Display(int width, int height)
{
	setArguments(width, height, 0);
}

Display::Display(int width, int height, int refreshRate)
{
	setArguments(width, height, refreshRate);
}

Display::~Display()
{
}

int Display::getWidth() const {
	return width;
}

int Display::getHeight() const {
	return height;
}

int Display::getRefreshRate() const {
	return refreshRate;
}

void Display::input() {
	int width, height, refreshRate;

	std::cout << "Введите ширину и высоту экрана (в пикселях): ";
	std::cin >> width >> height;
	std::cout << "Введите частоту обновления экрана (в Гц): ";
	std::cin >> refreshRate;
	while (getchar() != '\n');
	
	setArguments(width, height, refreshRate);
}


bool Display::checkArguments(int width, int height, int refreshRate) {
	return width >= 0 && height >= 0 && refreshRate >= 0;
}

void Display::setArguments(int width, int height, int refreshRate) {
	if (checkArguments(width, height, refreshRate)) {
		this->width = width;
		this->height = height;
		this->refreshRate = refreshRate;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}
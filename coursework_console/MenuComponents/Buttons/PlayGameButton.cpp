#include <conio.h>
#include "PlayGameButton.h"

PlayGameButton::PlayGameButton(const std::string& text) : Button(text)
{
	
}

void PlayGameButton::execute()
{
	std::cout << "К сожалению, Алексей еще не реализовал игру! Также прошу напомнить ему, что он должен забрать кроссовки со спортманежа!" << std::endl;
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}
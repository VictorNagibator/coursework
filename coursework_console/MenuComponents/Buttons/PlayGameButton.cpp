#include <conio.h>
#include "PlayGameButton.h"

PlayGameButton::PlayGameButton(const std::string& text) : Button(text)
{
	
}

void PlayGameButton::execute()
{
	std::cout << "� ���������, ������� ��� �� ���������� ����! ����� ����� ��������� ���, ��� �� ������ ������� ��������� �� �����������!" << std::endl;
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
}
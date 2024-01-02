#include <fstream>
#include <string>
#include <conio.h>
#include "OpenLoggerButton.h"

OpenLoggerButton::OpenLoggerButton(const std::string& title) : Button(title)
{
	
}

void OpenLoggerButton::execute()
{
	std::ifstream loggerFile("..\\log.txt");
	std::string line;
	while (std::getline(loggerFile, line))
	{
		std::cout << line << std::endl;
	}
	loggerFile.close();
	std::cout << "Нажмите любую клавишу для продолжения...";
	_getch();
}
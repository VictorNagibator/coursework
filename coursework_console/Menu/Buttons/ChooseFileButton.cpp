#include <string>
#include <conio.h>
#include "ChooseFileButton.h"
#include "../DatabaseConnector.h"

ChooseFileButton::ChooseFileButton() : Button("Выход") {

}

ChooseFileButton::ChooseFileButton(const std::string& text) : Button(text) {

}

void ChooseFileButton::execute() {
	system("cls");
	std::cout << "Введите путь к файлу (или напишите default, чтобы выбрать стандартный файл в папке с проектом): ";
	std::string path;
	std::getline(std::cin, path);

	if (path == "default") {
		path = "D:/Projects/coursework/default.accdb";
	}
	else {
		path = path + ".accdb";
	}

	DatabaseConnector databaseConnector(path);
	databaseConnector.connect();
	_getch();
	databaseConnector.disconnect();
}
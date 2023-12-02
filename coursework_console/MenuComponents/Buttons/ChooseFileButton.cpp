#include <string>
#include <fstream>
#include <conio.h>
#include "ChooseFileButton.h"
#include "../FileInfo.h"

ChooseFileButton::ChooseFileButton() : Button("Выбор файла") {

}

ChooseFileButton::ChooseFileButton(const std::string& text) : Button(text) {

}

void ChooseFileButton::execute() {
	system("cls");
	std::cout << "Введите путь к файлу (или напишите default, чтобы выбрать стандартный файл в папке с проектом): ";
	std::string path;
	std::getline(std::cin, path);

	if (path == "default") {
		path = "..\\orders.json";
	}

	std::ifstream file(path);

	if (path.find(".json") == std::string::npos) {
		std::cout << "Неверный формат файла. Пожалуйста, выберите файл с расширением .json." << std::endl;
	} 
	else if (file.is_open()) {
		std::cout << "Файл успешно открыт." << std::endl;
		FileInfo::setPath(path);
		file.close();
	} 
	else {
		std::cout << "Файл не найден. Проверьте правильность введенного пути." << std::endl;
	}
	std::cout << "Нажмите любую клавишу, чтобы продолжить...";
	_getch();
	system("cls");
}
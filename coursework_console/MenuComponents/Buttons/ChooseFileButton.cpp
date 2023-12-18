#include <string>
#include <fstream>
#include <conio.h>
#include "ChooseFileButton.h"
#include "../FileInfo.h"
#include "../OrdersData.h"

ChooseFileButton::ChooseFileButton() : Button("����� �����") {

}

ChooseFileButton::ChooseFileButton(const std::string& text) : Button(text) {

}

void ChooseFileButton::execute() {
	system("cls");
	std::cout << "������� ���� � ����� (��� �������� default, ����� ������� ����������� ���� � ����� � ��������): ";
	std::string path;
	std::getline(std::cin, path);

	if (path == "default") {
		path = "..\\orders.json";
	}

	std::ifstream file(path);

	if (path.find(".json") == std::string::npos) {
		std::cout << "�������� ������ �����. ����������, �������� ���� � ����������� .json." << std::endl;
	} 
	else if (file.is_open()) {
		std::cout << "���� ������� ������." << std::endl;
		FileInfo::setPath(path);
		file.close();

		std::ifstream properties("..\\properties.json");
		json propertiesJson = json::parse(properties);
		properties.close();
		propertiesJson["lastFile"] = path;
		std::ofstream propertiesOut("..\\properties.json");
		propertiesOut << propertiesJson.dump(4) << std::endl;
	} 
	else {
		std::cout << "���� �� ������. ��������� ������������ ���������� ����." << std::endl;
	}
	std::cout << "������� ����� �������, ����� ����������...";
	_getch();
}
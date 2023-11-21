#include "Menu.h"

Menu::Menu(const std::string& name) {
	this->name = name;
}

Menu::Menu(const std::string& name, std::vector<Button*> buttons) {
	this->name = name;
	this->buttons = buttons;
}

void Menu::addButton(Button* button) {
	buttons.push_back(button);
}
void Menu::removeButton(Button* button) {
	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i] == button) {
			buttons.erase(buttons.begin() + i);
			break;
		}
	}
}

void Menu::removeLastButton() {
	buttons.pop_back();
}

void Menu::show() {
	std::cout << name << std::endl;
	for (int i = 0; i < buttons.size(); i++) {
		std::cout << i + 1 << ". ";
		std::cout << buttons[i]->getText() << std::endl;
	}
	chooseButton();
}

void Menu::execute() {
	show();
}

void Menu::chooseButton()
{
	std::cout << "Ваш выбор: ";
	int choice;
	std::cin >> choice;
	system("cls");
	if (choice > 0 && choice <= buttons.size()) {
		system("cls");
		buttons[choice - 1]->execute();
	}
	else {
		std::cout << "Такого пункта меню нету! Попробуйте еще раз!" << std::endl;
		std::cout << "Нажмите любую клавишу...";
		_getch();
		system("cls");
		show();
	}
}
#include "ExitButton.h"

ExitButton::ExitButton() : Button("Выход") {
	
}

ExitButton::ExitButton(const std::string& text) : Button(text) {

}

void ExitButton::execute() {
	exit(0);
}
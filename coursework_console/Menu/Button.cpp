#include "Button.h"

Button::Button(const std::string& text, MenuItem* action) {
	this->text = text;
	this->action = action; 
}

void Button::execute() {
	action->execute();
}

std::string Button::getText() {
	return text;
}
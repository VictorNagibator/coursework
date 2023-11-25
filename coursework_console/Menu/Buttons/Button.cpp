#include "Button.h"

Button::Button(const std::string& text) {
	this->text = text;
}

std::string Button::getText() {
	return text;
}
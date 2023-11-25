#include "StandartMenuDirector.h"
#include "MenuBuilder.h"
#include "Buttons/ExitButton.h"
#include "Buttons/ChooseFileButton.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	builder.addButton(new ChooseFileButton("Выбрать файл"));
	builder.addButton(new ExitButton("Выйти"));
}
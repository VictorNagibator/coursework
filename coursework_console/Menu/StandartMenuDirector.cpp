#include "StandartMenuDirector.h"
#include "MenuBuilder.h"
#include "Buttons/ExitButton.h"
#include "Buttons/ChooseFileButton.h"
#include "Buttons/OpenMenuButton.h"
#include "Buttons/BackButton.h"
#include "MenuWithTable.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	MenuWithTable* menuWithTable = new MenuWithTable("Работа с таблицей");
	menuWithTable->addButton(new OpenMenuButton("Вывести полную таблицу", new MenuWithTable("Вывод таблицы")));
	menuWithTable->addButton(new OpenMenuButton("Добавить запись", new MenuWithTable("Добавление записи")));
	menuWithTable->addButton(new OpenMenuButton("Удалить запись", new MenuWithTable("Удаление записи")));
	menuWithTable->addButton(new BackButton("Вернуться", builder.getMenu()));
	builder.addButton(new OpenMenuButton("Открыть таблицу", menuWithTable));
	builder.addButton(new ChooseFileButton("Выбрать файл"));
	builder.addButton(new ExitButton("Выйти"));
}
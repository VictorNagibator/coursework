#include "StandartMenuDirector.h"
#include "MenuBuilder.h"
#include "../Buttons/ExitButton.h"
#include "../Buttons/ChooseFileButton.h"
#include "../Buttons/OpenMenuButton.h"
#include "../Buttons/BackButton.h"
#include "../Buttons/PlayGameButton.h"
#include "../Buttons/ShowTableButton.h"
#include "../Buttons/AddDataButton.h"
#include "../Buttons/DeleteDataButton.h"
#include "MenuWithTable.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	MenuWithTable* menuWithTable = new MenuWithTable("Работа с таблицей");
	menuWithTable->addButton(new ShowTableButton("Показать полную таблицу"));
	menuWithTable->addButton(new AddDataButton("Добавить запись"));
	menuWithTable->addButton(new DeleteDataButton("Удалить запись"));
	menuWithTable->addButton(new BackButton("Вернуться", builder.getMenu()));
	builder.addButton(new OpenMenuButton("Открыть таблицу", menuWithTable));
	builder.addButton(new ChooseFileButton("Выбрать файл"));
	builder.addButton(new PlayGameButton("Играть"));
	builder.addButton(new ExitButton("Выйти"));
}
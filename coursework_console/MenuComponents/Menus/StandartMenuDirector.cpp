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
#include "../Buttons/ChooseOrderButton.h"
#include "../Buttons/ChangeOrderButton.h"
#include "../Buttons/FindOrderButton.h"
#include "../Buttons/BoostComponentButton.h"
#include "MenuWithTable.h"
#include "ChangeOrderMenu.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	MenuWithTable* menuWithTable = new MenuWithTable("Работа с данными");
	menuWithTable->addButton(new ShowTableButton("Показать полную таблицу"));
	menuWithTable->addButton(new FindOrderButton("Найти заказ по ID"));
	menuWithTable->addButton(new AddDataButton("Добавить запись"));
	ChangeOrderMenu* changeOrderMenu = new ChangeOrderMenu("Редактирование записей");
	menuWithTable->addButton(new ChooseOrderButton("Редактировать запись", changeOrderMenu));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить статус заказа", changeOrderMenu, ChangableObject::Status));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить дополнительную информацию заказа", changeOrderMenu, ChangableObject::AdditionalInfo));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить название ноутбука", changeOrderMenu, ChangableObject::LaptopName));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить процессор ноутбука", changeOrderMenu, ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new BoostComponentButton("Разогнать процессор ноутбука", changeOrderMenu, ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить видеокарту ноутбука", changeOrderMenu, ChangableObject::LaptopGPU));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить оперативную память ноутбука", changeOrderMenu, ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new BoostComponentButton("Разогнать оперативную память ноутбука", changeOrderMenu, ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить материнскую плату ноутбука", changeOrderMenu, ChangableObject::LaptopMotherboard));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить хранилище данных ноутбука", changeOrderMenu, ChangableObject::LaptopStorage));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить дисплей ноутбука", changeOrderMenu, ChangableObject::LaptopDisplay));
	changeOrderMenu->addButton(new BackButton("Вернуться", menuWithTable));
	menuWithTable->addButton(new DeleteDataButton("Удалить запись"));
	menuWithTable->addButton(new BackButton("Вернуться", builder.getMenu()));
	builder.addButton(new OpenMenuButton("Работа с данными", menuWithTable));
	builder.addButton(new ChooseFileButton("Выбрать файл"));
	builder.addButton(new PlayGameButton("Играть"));
	builder.addButton(new ExitButton("Выйти"));
}
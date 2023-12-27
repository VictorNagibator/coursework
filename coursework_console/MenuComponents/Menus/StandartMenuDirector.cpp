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
#include "MenuWithTable.h"
#include "ChangeOrderMenu.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	MenuWithTable* menuWithTable = new MenuWithTable("Работа с данными");
	menuWithTable->addButton(new ShowTableButton("Показать полную таблицу"));
	menuWithTable->addButton(new AddDataButton("Добавить запись"));
	ChangeOrderMenu* changeOrderMenu = new ChangeOrderMenu("Редактирование записей");
	menuWithTable->addButton(new ChooseOrderButton("Редактировать запись", changeOrderMenu));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить статус заказа", changeOrderMenu->getOrder(), ChangableObject::Status));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить дополнительную информацию заказа", changeOrderMenu->getOrder(), ChangableObject::AdditionalInfo));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить название ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopName));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить процессор ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить видеокарту ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopGPU));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить оперативную память ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить материнскую плату ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopMotherboard));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить хранилище данных ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopStorage));
	changeOrderMenu->addButton(new ChangeOrderButton("Изменить дисплей ноутбука", changeOrderMenu->getOrder(), ChangableObject::LaptopDisplay));
	changeOrderMenu->addButton(new BackButton("Вернуться", menuWithTable));
	menuWithTable->addButton(new DeleteDataButton("Удалить запись"));
	menuWithTable->addButton(new BackButton("Вернуться", builder.getMenu()));
	builder.addButton(new OpenMenuButton("Работа с данными", menuWithTable));
	builder.addButton(new ChooseFileButton("Выбрать файл"));
	builder.addButton(new PlayGameButton("Играть"));
	builder.addButton(new ExitButton("Выйти"));
}
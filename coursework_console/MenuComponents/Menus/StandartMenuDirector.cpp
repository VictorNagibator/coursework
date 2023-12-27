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
	MenuWithTable* menuWithTable = new MenuWithTable("������ � �������");
	menuWithTable->addButton(new ShowTableButton("�������� ������ �������"));
	menuWithTable->addButton(new AddDataButton("�������� ������"));
	ChangeOrderMenu* changeOrderMenu = new ChangeOrderMenu("�������������� �������");
	menuWithTable->addButton(new ChooseOrderButton("������������� ������", changeOrderMenu));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ������ ������", changeOrderMenu->getOrder(), ChangableObject::Status));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� �������������� ���������� ������", changeOrderMenu->getOrder(), ChangableObject::AdditionalInfo));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� �������� ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopName));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ��������� ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ���������� ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopGPU));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ����������� ������ ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ����������� ����� ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopMotherboard));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ��������� ������ ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopStorage));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ������� ��������", changeOrderMenu->getOrder(), ChangableObject::LaptopDisplay));
	changeOrderMenu->addButton(new BackButton("���������", menuWithTable));
	menuWithTable->addButton(new DeleteDataButton("������� ������"));
	menuWithTable->addButton(new BackButton("���������", builder.getMenu()));
	builder.addButton(new OpenMenuButton("������ � �������", menuWithTable));
	builder.addButton(new ChooseFileButton("������� ����"));
	builder.addButton(new PlayGameButton("������"));
	builder.addButton(new ExitButton("�����"));
}
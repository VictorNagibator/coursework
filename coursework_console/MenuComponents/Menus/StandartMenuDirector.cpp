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
	MenuWithTable* menuWithTable = new MenuWithTable("������ � �������");
	menuWithTable->addButton(new ShowTableButton("�������� ������ �������"));
	menuWithTable->addButton(new FindOrderButton("����� ����� �� ID"));
	menuWithTable->addButton(new AddDataButton("�������� ������"));
	ChangeOrderMenu* changeOrderMenu = new ChangeOrderMenu("�������������� �������");
	menuWithTable->addButton(new ChooseOrderButton("������������� ������", changeOrderMenu));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ������ ������", changeOrderMenu, ChangableObject::Status));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� �������������� ���������� ������", changeOrderMenu, ChangableObject::AdditionalInfo));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� �������� ��������", changeOrderMenu, ChangableObject::LaptopName));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ��������� ��������", changeOrderMenu, ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new BoostComponentButton("��������� ��������� ��������", changeOrderMenu, ChangableObject::LaptopCPU));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ���������� ��������", changeOrderMenu, ChangableObject::LaptopGPU));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ����������� ������ ��������", changeOrderMenu, ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new BoostComponentButton("��������� ����������� ������ ��������", changeOrderMenu, ChangableObject::LaptopRAM));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ����������� ����� ��������", changeOrderMenu, ChangableObject::LaptopMotherboard));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ��������� ������ ��������", changeOrderMenu, ChangableObject::LaptopStorage));
	changeOrderMenu->addButton(new ChangeOrderButton("�������� ������� ��������", changeOrderMenu, ChangableObject::LaptopDisplay));
	changeOrderMenu->addButton(new BackButton("���������", menuWithTable));
	menuWithTable->addButton(new DeleteDataButton("������� ������"));
	menuWithTable->addButton(new BackButton("���������", builder.getMenu()));
	builder.addButton(new OpenMenuButton("������ � �������", menuWithTable));
	builder.addButton(new ChooseFileButton("������� ����"));
	builder.addButton(new PlayGameButton("������"));
	builder.addButton(new ExitButton("�����"));
}
#include "StandartMenuDirector.h"
#include "MenuBuilder.h"
#include "Buttons/ExitButton.h"
#include "Buttons/ChooseFileButton.h"
#include "Buttons/OpenMenuButton.h"
#include "Buttons/BackButton.h"
#include "MenuWithTable.h"

void StandartMenuDirector::buildMenu(MenuBuilder& builder) {
	MenuWithTable* menuWithTable = new MenuWithTable("������ � ��������");
	menuWithTable->addButton(new OpenMenuButton("������� ������ �������", new MenuWithTable("����� �������")));
	menuWithTable->addButton(new OpenMenuButton("�������� ������", new MenuWithTable("���������� ������")));
	menuWithTable->addButton(new OpenMenuButton("������� ������", new MenuWithTable("�������� ������")));
	menuWithTable->addButton(new BackButton("���������", builder.getMenu()));
	builder.addButton(new OpenMenuButton("������� �������", menuWithTable));
	builder.addButton(new ChooseFileButton("������� ����"));
	builder.addButton(new ExitButton("�����"));
}
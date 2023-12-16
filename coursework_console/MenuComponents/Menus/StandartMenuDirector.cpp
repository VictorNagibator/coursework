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
	MenuWithTable* menuWithTable = new MenuWithTable("������ � ��������");
	menuWithTable->addButton(new ShowTableButton("�������� ������ �������"));
	menuWithTable->addButton(new AddDataButton("�������� ������"));
	menuWithTable->addButton(new DeleteDataButton("������� ������"));
	menuWithTable->addButton(new BackButton("���������", builder.getMenu()));
	builder.addButton(new OpenMenuButton("������� �������", menuWithTable));
	builder.addButton(new ChooseFileButton("������� ����"));
	builder.addButton(new PlayGameButton("������"));
	builder.addButton(new ExitButton("�����"));
}
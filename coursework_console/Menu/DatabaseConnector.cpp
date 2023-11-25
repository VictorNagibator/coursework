#include "DatabaseConnector.h"

DatabaseConnector::DatabaseConnector(std::string path) {
	this->path = path;
}

DatabaseConnector::~DatabaseConnector() {
	disconnect();
}

void DatabaseConnector::setPath(const std::string& path) {
	this->path = path;
}

void DatabaseConnector::connect() {
	this->pConnection.CreateInstance(__uuidof(Connection));

	std::string fullCommand = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + path + ";Persist Security Info=False; ";
	try
	{
		pConnection->Open(fullCommand.c_str(), "", "", adConnectUnspecified);
		std::cout << "�������� ����������� � �����!";
	}
	catch (_com_error& e)
	{
		std::cout << "�� ������� ������������ � ���� ������. ���������, ��� ���� ���������� � ���� � ���� ������ �����.";
	}
}

void DatabaseConnector::disconnect() {
	if (pConnection != NULL && pConnection->State == adStateOpen) {
		pConnection->Close();
	}
}
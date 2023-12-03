#include <fstream>
#include "AddDataButton.h"
#include "../../OrderComponents/Order.h"
#include "../FileInfo.h"

AddDataButton::AddDataButton(const std::string& title) : Button(title)
{

}

void AddDataButton::execute() 
{
	loadJSON();
	Order o = Order();
	o.input();
	json j = o.toJSON();
	this->data.push_back(j);
	saveJSON();
}

void AddDataButton::loadJSON()
{
	std::ifstream file(FileInfo::getPath());
	this->data = json::parse(file);
	file.close();
}

void AddDataButton::saveJSON()
{
	std::ofstream file(FileInfo::getPath());
	file << this->data;
	file.close();
}
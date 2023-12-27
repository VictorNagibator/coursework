#include <nlohmann/json.hpp>
#include <fstream>
#include <conio.h>
#include "OrdersData.h"
#include "FileInfo.h"

using json = nlohmann::json;

Order OrdersData::getOrder(int idOfOrder) {
	auto gettable = std::find_if(data.begin(), data.end(), [&](Order order) {
		return order.getNumOfOrder() == idOfOrder;
	});

	if (gettable != data.end()) {
		return *gettable;
	}
	else {
		throw std::invalid_argument("������ � ����� id �� ����������!");
	}
}

std::vector<Order> OrdersData::getData() {
	return data;
}

void OrdersData::loadOrders(const std::string& filePath) {
	if (isDataLoaded) {
		return;
	}
	isDataLoaded = true;

	std::ifstream file(filePath);
	if (!file.is_open()) {
		throw std::invalid_argument("���� �� ������!");
	}
	json j = json::parse(file);
	file.close();
	
	for (auto& element : j) {
		Order order = Order();
		order.fromJSON(element);
		data.push_back(order);
	}

	verifyIDs();
}

void OrdersData::saveOrders(const std::string& filePath) {
	json j;
	for (auto& element : data) {
		j.push_back(element.toJSON());
	}

	std::ofstream file(filePath);
	file << j.dump(4) << std::endl;
	file.close();
}

void OrdersData::addOrder(Order order) {
	data.push_back(order);
	verifyIDs();
}

void OrdersData::removeOrder(int idOfOrder) {
	auto removable = std::find_if(data.begin(), data.end(), [&](Order order) {
		return order.getNumOfOrder() == idOfOrder;
	});

	if (removable != data.end()) {
		data.erase(removable);
	}
	else {
		throw std::invalid_argument("������ � ����� id �� ����������!");
	}
}

void OrdersData::editOrder(Order newOrder, ChangableObject object) {
	try
	{
		StatusType type;
		std::string tempString;
		Laptop newLaptop = newOrder.getLaptop();

		switch (object)
		{
		case ChangableObject::Status:
			std::cout << "������� ������ ������ (0 - � ��������, 1 - � �������, 2 - ��������������): ";
			std::cin >> type;
			std::cin.clear();
			while (std::cin.get() != '\n');

			newOrder.setStatus(type);
			break;
		case ChangableObject::AdditionalInfo:
			std::cout << "������� �������������� ����������: ";
			std::getline(std::cin, tempString);

			newOrder.setAdditionalInfo(tempString);
			break;
		case ChangableObject::LaptopName:
			newLaptop.inputModelName();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopCPU:
			newLaptop.inputCPU();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopGPU:
			newLaptop.inputGPU();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopRAM:
			newLaptop.inputRAM();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopStorage:
			newLaptop.inputDataStorage();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopDisplay:
			newLaptop.inputDisplay();
			newOrder.setLaptop(newLaptop);
			break;
		case ChangableObject::LaptopMotherboard:
			newLaptop.inputMotherboard();
			newOrder.setLaptop(newLaptop);
			break;
		default:
			break;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}

	auto editable = std::find_if(data.begin(), data.end(), [&](Order order) {
		return order.getNumOfOrder() == newOrder.getNumOfOrder();
	});

	if (editable != data.end()) {
		data[editable - data.begin()] = newOrder;
	}
	else {
		throw std::invalid_argument("������ � ����� id �� ����������!");
	}
}

void OrdersData::verifyIDs() {
	std::ifstream file("..\\properties.json");
	json j = json::parse(file);
	file.close();

	if (j.contains(FileInfo::getPath())) {
		j[FileInfo::getPath()] = 0;
	}
	int maxID = j[FileInfo::getPath()];
	if (maxID < Order::getNumOfLastOrder()) {
		j[FileInfo::getPath()] = Order::getNumOfLastOrder();
	}
	else {
		while (Order::getNumOfLastOrder() < maxID) {
			Order order = Order();
		}
	}
	
	std::ofstream file2("..\\properties.json");
	file2 << j.dump(4) << std::endl;
	file2.close();
}
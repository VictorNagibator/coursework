#include <nlohmann/json.hpp>
#include <fstream>
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
		throw std::invalid_argument("Заказа с таким id не существует!");
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
		throw std::invalid_argument("Файл не найден!");
	}
	json j = json::parse(file);
	file.close();
	
	for (auto& element : j) {
		Order order = Order();
		order.fromJSON(element);
		data.push_back(order);
	}
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
}

void OrdersData::removeOrder(int idOfOrder) {
	auto removable = std::find_if(data.begin(), data.end(), [&](Order order) {
		return order.getNumOfOrder() == idOfOrder;
	});

	if (removable != data.end()) {
		data.erase(removable);
	}
	else {
		throw std::invalid_argument("Заказа с таким id не существует!");
	}
}

void OrdersData::editOrder(int idOfOrder, Order order) {
	auto editable = std::find_if(data.begin(), data.end(), [&](Order order) {
		return order.getNumOfOrder() == idOfOrder;
	});

	if (editable != data.end()) {
		data[editable - data.begin()] = order;
	}
	else {
		throw std::invalid_argument("Заказа с таким id не существует!");
	}
}
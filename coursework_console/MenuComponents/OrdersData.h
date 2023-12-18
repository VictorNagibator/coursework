#pragma once
#include "../OrderComponents/Order.h"

class OrdersData
{
public:
	static Order getOrder(int idOfOrder);
	static std::vector<Order> getData();
	static void loadOrders(const std::string& filePath);
	static void saveOrders(const std::string& filePath);
	static void addOrder(Order order);
	static void removeOrder(int idOfOrder);
	static void editOrder(int idOfOrder, Order order);
	static void verifyIDs();
private:
	static inline bool isDataLoaded{};
	static inline std::vector<Order> data;
};
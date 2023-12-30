#pragma once
#include "../OrderComponents/Order.h"
#include "ChangableObject.h"

class OrdersData
{
public:
	static Order getOrder(int idOfOrder);
	static std::vector<Order> getData();
	static void loadOrders(const std::string& filePath);
	static void saveOrders(const std::string& filePath);
	static void addOrder(Order order);
	static void removeOrder(int idOfOrder);
	static void editOrder(Order newOrder, ChangableObject object);
	static void boostLaptopComponent(Order newOrder, ChangableObject object);
	static void verifyIDs();
	static bool isDataEmpty();
private:
	static inline bool isDataLoaded{};
	static inline std::vector<Order> data;
};
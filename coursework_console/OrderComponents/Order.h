#pragma once
#include <iostream>
#include <istream>
#include <concepts>
#include "Laptop.h"
#include "StatusType.h"

class Order
{
public:
	Order(Laptop laptop);
	Order(Laptop laptop, StatusType status, std::string additionalInfo);
	~Order() = default;

	friend std::ostream& operator << (std::ostream& out, Order& order);

	static int getNumOfLastOrder();
	int getNumOfOrder() const;
	const Laptop& getLaptop() const;
	StatusType getStatus() const;
	std::string getAdditionalInfo() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
	void setAdditionalInfo(std::string additionalInfo);
	std::string toString() const;
private:
	static inline int numOfLastOrder{};

	int numOfOrder;
	Laptop laptop = Laptop();
	StatusType status = StatusType::ONHOLD;
	std::string additionalInfo;
};
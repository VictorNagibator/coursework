﻿#pragma once
#include <iostream>
#include <istream>
#include <concepts>
#include "Laptop.h"
#include "StatusType.h"

using json = nlohmann::json;

class Order
{
public:
	Order();
	Order(Laptop laptop);
	Order(Laptop laptop, StatusType status, std::string additionalInfo);
	Order(json j);
	~Order() = default;

	void operator=(Order other);
	friend std::ostream& operator << (std::ostream& out, Order& order);

	static int getLastID();
	int getID() const;
	const Laptop& getLaptop() const;
	StatusType getStatus() const;
	std::string getAdditionalInfo() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
	void setAdditionalInfo(std::string additionalInfo);
	std::string toString() const;

	json toJSON() const;
	void fromJSON(json j);
private:
	static inline int lastID{};

	int id;
	Laptop laptop = Laptop();
	StatusType status = StatusType::ONHOLD;
	std::string additionalInfo;
};
#pragma once
#include "Laptop.h"

enum StatusType { ONHOLD, INPROCCESS, FINISHED };

std::istream& operator >> (std::istream& in, StatusType& status);
std::ostream& operator << (std::ostream& out, StatusType& status);

class Order
{
public:
	Order();
	Order(Laptop laptop);
	Order(int num, Laptop laptop, StatusType status);
	~Order();

	void operator=(Order other);
	friend std::ostream& operator << (std::ostream& out, Order& order);

	int getNum() const;
	Laptop getLaptop() const;
	StatusType getStatus() const;
	void input();
	void setStatus(StatusType status);
	void setLaptop(Laptop laptop);
private:
	int num;
	Laptop laptop;
	StatusType status;

	bool checkArguments(int num, Laptop laptop, StatusType status);
};
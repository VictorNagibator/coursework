#pragma once
#include <iostream>
#include <istream>

enum class StatusType { ONHOLD, INPROCESS, FINISHED };

static std::string statusTypeToString(StatusType type) {
	std::string result;
	switch (type)
	{
	case StatusType::ONHOLD:
		result = "ONHOLD";
		break;
	case StatusType::INPROCESS:
		result = "INPROCESS";
		break;
	case StatusType::FINISHED:
		result = "FINISHED";
		break;
	default:
		break;
	}
	return result;
}

static StatusType stringToStatusType(std::string type) {
	StatusType result;
	if (type == "ONHOLD") {
		result = StatusType::ONHOLD;
	}
	else if (type == "INPROCESS") {
		result = StatusType::INPROCESS;
	}
	else if (type == "FINISHED") {
		result = StatusType::FINISHED;
	}
	else {
		throw std::invalid_argument("Некорректный статус!");
	}
	return result;
}

static std::istream& operator >> (std::istream& in, StatusType& status) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		status = StatusType::ONHOLD;
		break;
	case 1:
		status = StatusType::INPROCESS;
		break;
	case 2:
		status = StatusType::FINISHED;
		break;
	default:
		break;
	}
	return in;
};

static std::ostream& operator << (std::ostream& out, StatusType& status) {
	out << statusTypeToString(status);
	return out;
};
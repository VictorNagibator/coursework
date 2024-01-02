#pragma once
#include <iostream>
#include <istream>

enum class StatusType { ONHOLD, INPROCCESS, FINISHED };

static std::string statusTypeToString(StatusType type) {
	std::string result;
	switch (type)
	{
	case StatusType::ONHOLD:
		result = "On hold";
		break;
	case StatusType::INPROCCESS:
		result = "In proccess";
		break;
	case StatusType::FINISHED:
		result = "Finished";
		break;
	default:
		break;
	}
	return result;
}

static StatusType stringToStatusType(std::string type) {
	StatusType result;
	if (type == "On hold") {
		result = StatusType::ONHOLD;
	}
	else if (type == "In proccess") {
		result = StatusType::INPROCCESS;
	}
	else if (type == "Finished") {
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
		status = StatusType::INPROCCESS;
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
#pragma once
#include <iostream>

enum class FlashMemoryType { SLC, MLC, NOR, NAND, NAND3D };

static std::string FlashMemoryTypeToString(FlashMemoryType type) {
	std::string result;
	switch (type)
	{
	case FlashMemoryType::SLC:
		result = "SLC";
		break;
	case FlashMemoryType::MLC:
		result = "MLC";
		break;
	case FlashMemoryType::NOR:
		result = "NOR";
		break;
	case FlashMemoryType::NAND:
		result = "NAND";
		break;
	case FlashMemoryType::NAND3D:
		result = "NAND3D";
		break;
	default:
		break;
	}
	return result;
}

static FlashMemoryType stringToFlashMemoryType(std::string type) {
	FlashMemoryType result;
	if (type == "SLC") {
		result = FlashMemoryType::SLC;
	}
	else if (type == "MLC") {
		result = FlashMemoryType::MLC;
	}
	else if (type == "NOR") {
		result = FlashMemoryType::NOR;
	}
	else if (type == "NAND") {
		result = FlashMemoryType::NAND;
	}
	else if (type == "NAND3D") {
		result = FlashMemoryType::NAND3D;
	}
	else {
		throw std::invalid_argument("Некорректный тип флеш-памяти!");
	}
	return result;
}

static std::istream& operator >> (std::istream& in, FlashMemoryType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = FlashMemoryType::SLC;
		break;
	case 1:
		type = FlashMemoryType::MLC;
		break;
	case 2:
		type = FlashMemoryType::NOR;
		break;
	case 3:
		type = FlashMemoryType::NAND;
		break;
	case 4:
		type = FlashMemoryType::NAND3D;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, FlashMemoryType& type) {
	out << FlashMemoryTypeToString(type);
	return out;
};
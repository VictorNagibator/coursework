#pragma once

enum class RAMType { DDR, DDR2, DDR3, DDR4, DDR5 };

static std::string RAMTypeToString(RAMType type) {
	std::string result;
	switch (type)
	{
	case RAMType::DDR:
		result = "DDR";
		break;
	case RAMType::DDR2:
		result = "DDR2";
		break;
	case RAMType::DDR3:
		result = "DDR3";
		break;
	case RAMType::DDR4:
		result = "DDR4";
		break;
	case RAMType::DDR5:
		result = "DDR5";
		break;
	default:
		break;
	}
	return result;
}

static RAMType stringToRAMType(std::string type) {
	RAMType result;
	if (type == "DDR") {
		result = RAMType::DDR;
	}
	else if (type == "DDR2") {
		result = RAMType::DDR2;
	}
	else if (type == "DDR3") {
		result = RAMType::DDR3;
	}
	else if (type == "DDR4") {
		result = RAMType::DDR4;
	}
	else if (type == "DDR5") {
		result = RAMType::DDR5;
	}
	else {
		throw std::invalid_argument("Некорректный тип оперативной памяти!");
	}
	return result;
}

static int RAMTypeToInt(RAMType type) {
	return static_cast<int>(type);
}

static std::istream& operator >> (std::istream& in, RAMType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = RAMType::DDR;
		break;
	case 1:
		type = RAMType::DDR2;
		break;
	case 2:
		type = RAMType::DDR3;
		break;
	case 3:
		type = RAMType::DDR4;
		break;
	case 4:
		type = RAMType::DDR5;
		break;
	default:
		break;
	}
	return in;
};

static std::ostream& operator << (std::ostream& out, RAMType& type) {
	out << RAMTypeToString(type);
	return out;
};
#pragma once

enum RAMType { DDR, DDR2, DDR3, DDR4, DDR5 };

static std::istream& operator >> (std::istream& in, RAMType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = DDR;
		break;
	case 1:
		type = DDR2;
		break;
	case 2:
		type = DDR3;
		break;
	case 3:
		type = DDR4;
		break;
	case 4:
		type = DDR5;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, RAMType& type) {
	switch (type)
	{
	case DDR:
		out << "DDR";
		break;
	case DDR2:
		out << "DDR2";
		break;
	case DDR3:
		out << "DDR3";
		break;
	case DDR4:
		out << "DDR4";
		break;
	case DDR5:
		out << "DDR5";
		break;
	default:
		break;
	}
	return out;
};
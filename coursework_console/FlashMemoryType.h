#pragma once

enum FlashMemoryType { SLC, MLC, NOR, NAND, NAND3D };

static std::istream& operator >> (std::istream& in, FlashMemoryType& type) {
	int choice;
	in >> choice;
	switch (choice)
	{
	case 0:
		type = SLC;
		break;
	case 1:
		type = MLC;
		break;
	case 2:
		type = NOR;
		break;
	case 3:
		type = NAND;
		break;
	case 4:
		type = NAND3D;
		break;
	default:
		break;
	}
	return in;
};
static std::ostream& operator << (std::ostream& out, FlashMemoryType& type) {
	switch (type)
	{
	case SLC:
		out << "SLC";
		break;
	case MLC:
		out << "MLC";
		break;
	case NOR:
		out << "NOR";
		break;
	case NAND:
		out << "NAND";
		break;
	case NAND3D:
		out << "3D NAND";
		break;
	default:
		break;
	}
	return out;
};
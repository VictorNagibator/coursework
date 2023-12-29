#pragma once

enum class OrderOperation
{
	Adding,
	Editing,
	Removing
};

inline std::ostream& operator <<(std::ostream& out, OrderOperation operation) {
	switch (operation) {
	case OrderOperation::Adding:
		out << "��������";
		break;
	case OrderOperation::Editing:
		out << "�������";
		break;
	case OrderOperation::Removing:
		out << "������";
		break;
	}
	return out;
}
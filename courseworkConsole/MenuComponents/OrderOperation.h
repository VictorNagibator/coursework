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
		out << "добавлен";
		break;
	case OrderOperation::Editing:
		out << "изменен";
		break;
	case OrderOperation::Removing:
		out << "удален";
		break;
	}
	return out;
}
#include "bad_login.h"

const char* BadLogin::what() const
{
	return "Пользователь не найден!\nХотите повторить ввод?(y/n): ";
}

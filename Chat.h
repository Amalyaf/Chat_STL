#pragma once
#include <vector>
#include "Users.h"
#include "Message.h"

class Chat
{
private:
	std::vector<Users> allUsers; // все зарегистрированные пользователи
	std::string _recipient; //получатель сообщения
	std::string _sender; // отправитель сообщения
	std::string _login; // логин авторизованного пользователя
	std::string _password; // пароль авторизованного пользователя
	std::vector<Message>allMessage;
	bool _status = false; // если был выполнен вход статус = true, в противном случае - false.
public:
	Chat(); // конструктор
	~Chat()=default; // деструктор
	void getChat(); // метод выводит данные пользователя
	void enter(); // авторизация пользователя
	void registration(); //  регистрация пользователя
	void sendPrivateMessage(); // отправка личных сообщений
	void sendPublicMessage(); // отправка публичных сообщений
	bool getstatus(); // метод выводит статус авторизации (_status)
	void exit(); // разлогинить авторизованного пользователя
	void printMessage();
};

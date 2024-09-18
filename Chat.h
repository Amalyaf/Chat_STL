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
	std::vector<Message>allMessage; // все новые приватные сообщения
	std::vector<Message>allPublicMessage; // все новые общие сообщения
	std::vector<Message>viewedMessage; // просмотренные сообщения
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
	void printMessage(std::string recipient); // вывод на экран новых сообщений
	void deletePrivateMessage(std::string recipient); // перемещение прочитанных личных сообщений в viewedMessage и их удаление из allMessage
	void deletePublicMessage(std::string recipient); // удаление прочитанных общих сообщений из allPublicMessage
	void printAllMessage(); // вывод на экран всех просмотренных личных сообщений
	void start();
};

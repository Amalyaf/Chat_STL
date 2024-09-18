#include "Chat.h"
#include <algorithm>
#include "bad_login.h"
#include "bad_password.h"

using namespace std;
Chat::Chat()
{
	vector<Users>allUsers;
}

void Chat::getChat()
{
	for (vector<Users>::iterator it = allUsers.begin(); it < allUsers.end(); it++)
	{
		cout << *it << endl;
	}
}

void Chat::enter()
{
	char c = 'y';
	while (c != 'n')
	{
		try
		{
			cout << "\nДля входа введите логин: \n";
			cin >> _login;
			Users user;
			user._login = _login;
			vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);

			if (result == allUsers.end())
			{
				throw BadLogin();
			}

			else
			{
				user = *result;
				std::cout << "Введите пароль: \n";
				std::cin >> _password;
								
				if (user._password!=_password)
				{
					throw BadPassword();
				}
				else
				{
					_status = true;
					c = 'n';
					printMessage(_login);
				}
			}
		}
		catch (BadLogin& e)
		{
			std::cout << e.what() << std::endl;
			std::cin >> c;
		}
		catch (BadPassword& e)
		{
			std::cout << e.what() << std::endl;
			std::cin >> c;
		}
	}
}

void Chat::registration()
{
	char c = 'y';
		while (c != 'n')
		{
			cout << "Регистрация нового пользователя\n";
			Users user;
			user.setUser();
			vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
			if (result != allUsers.end())
			{
				cout << "\nПользователь с таким логином уже существует!\nХотите повторить попытку?(y/n)\n";
				cin >> c;
				cout << endl;
			}
			else
			{
				allUsers.push_back(user);
				c = 'n';
			}
		}
}

void Chat::sendPrivateMessage()
{
	char c = 'y';
	_sender = _login;
	while (c != 'n')
	{
		std::cout << "Кому: ";
		cin >> _recipient;
		Users user;
		user._login = _recipient;
		vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
		if (result == allUsers.end())
		{
			cout << "Получатель не найден!\nХотите повторить попытку?(y/n)";
			cin >> c;
		}

		else
		{
			Message message;
			message._recipient = _recipient;
			message._sender = _sender;
			std::cout << "Введите сообщение:\n";
			message.setMessage();
			allMessage.push_back(message);
			c = 'n';
		}
	}
}

void Chat::sendPublicMessage()
{
	Message message;
	message._sender = _login;
	std::cout << "Введите групповое сообщение:\n";
	message.setMessage();
	for (vector<Users>::iterator it = allUsers.begin(); it < allUsers.end(); it++)
	{
		if (it->_login != _login)
		{
			message._recipient = it->_login;
			allPublicMessage.push_back(message);
		}
	}

	message._recipient = "all";
	viewedMessage.push_back(message);
}


void Chat::printMessage(string recipient)
{
	int count = 0;
	for (vector<Message>::iterator it = allMessage.begin(); it < allMessage.end(); it++)
	{
		if (it->_recipient == recipient)
		{
			count++;
			if (count == 1)
			{
				std::cout << "\n------------------------------------------------------\n";
				std::cout << "У вас есть новые личные сообщения" << ": ";
			}
			cout << "\nОтправитель: " << it->_sender << endl <<
				"Получатель: " << it->_recipient << endl <<
				"Сообщение: " << it->_message << endl;
		}
	}
	if (count!=0)
	{
		std::cout << "\n------------------------------------------------------\n";
		deletePrivateMessage(recipient);
	}
	count = 0;
	for (vector<Message>::iterator it = allPublicMessage.begin(); it < allPublicMessage.end(); it++)
	{
		if (it->_recipient == recipient)
		{
			count++;
			if (count == 1)
			{
				std::cout << "\n------------------------------------------------------\n";
				std::cout << "У вас есть новые общие сообщения" << ": ";
			}
			cout << "\nОтправитель: " << it->_sender << endl <<
				"Сообщение: " << it->_message << endl;
		}
	}
	if (count!=0)
	{
		std::cout << "\n------------------------------------------------------\n";
		deletePublicMessage(recipient);
	}
}

void Chat::deletePrivateMessage(std::string recipient)
{
	for (vector<Message>::iterator it = allMessage.begin(); it < allMessage.end();)
	{
		if (it->_recipient == recipient)
		{
			viewedMessage.push_back(*it);
			it = allMessage.erase(it);
		}
		else
			++it;
	}
}

void Chat::deletePublicMessage(std::string recipient)
{
	for (vector<Message>::iterator it = allPublicMessage.begin(); it < allPublicMessage.end();)
	{
		if (it->_recipient == recipient)
		{
			it = allPublicMessage.erase(it);
		}
		else
			++it;
	}
}

void Chat::printAllMessage()
{
	for (vector<Message>::iterator it = viewedMessage.begin(); it != viewedMessage.end(); it++)
	{
		cout << "\nОтправитель: " << it->_sender << endl <<
			"Получатель: " << it->_recipient << endl <<
			"Сообщение: " << it->_message << endl;
	}
	cout << endl;
}

void Chat::start()
{
	char c = 'y'; // условие выхода из цикла
	while (c == 'y')
	{
		registration();
		cout << "\nХотите зарегистрировать ещё одного пользователя?" << endl;
		cin >> c;
		cout << endl;
	}

	enter(); // авторизация
	c = 'y';
	while (c != 'n')
	{
		if (getstatus()) // проверяем был ли выполнен вход
		{
			char message;
			cout << "\nХотите отправить сообщение?(y/n)\n";
			cin >> c;

			if (c == 'y')
			{
				cout << "\nВыберите тип отправляемого сообщения: 1-private, 2-public\n";
				cin >> message;
				switch (message)
				{
				case '1':
					sendPrivateMessage();
					break;
				case '2':
					sendPublicMessage();
					break;
				default:
					cout << "Некорректный ввод!";
					break;
				}
			}
			if (c == 'n')
			{
				cout << "\nХотите выполнить вход под другой учетной записью?(y/n)\n";
				cin >> c;
				if (c == 'y')
				{
					exit();
					enter();
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			c = 'n';
			cout << "Вход не выполнен!\n";
		}
	}
	printAllMessage();
}

bool Chat::getstatus()
{
	return _status;
}

void Chat::exit()
{
	_status = false;
	_login.clear();
	_password.clear();
}
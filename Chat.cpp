#include "Chat.h"
#include <algorithm>

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
				cout << "\nПользователь с таким логином уже существует!\nХотите повторить попытку?(y/n)";
				cin >> c;
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
	message._recipient = "all";
	message._sender = _login;
	std::cout << "Введите групповое сообщение:\n";
	message.setMessage();
	allMessage.push_back(message);
}

void Chat::printMessage()
{
	for (vector<Message>::iterator it = allMessage.begin(); it < allMessage.end(); it++)
	{
		cout << "\nОтправитель: " << it->_sender << endl <<
			"Получатель: " << it->_recipient << endl <<
			"Сообщение: " << it->_message << endl;
	}
}

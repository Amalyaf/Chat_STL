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
			cout << "\n��� ����� ������� �����: \n";
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
				std::cout << "������� ������: \n";
				std::cin >> _password;
				int i = 0;
				for (; i < allUsers.size(); i++)
				{
					if (allUsers[i]._password == _password)
						break;
				}
				
				if (i==allUsers.size())
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
			cout << "����������� ������ ������������\n";
			Users user;
			user.setUser();
			vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
			if (result != allUsers.end())
			{
				cout << "\n������������ � ����� ������� ��� ����������!\n������ ��������� �������?(y/n)";
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
		std::cout << "����: ";
		cin >> _recipient;
		Users user;
		user._login = _recipient;
		vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
		if (result == allUsers.end())
		{
			cout << "���������� �� ������!\n������ ��������� �������?(y/n)";
			cin >> c;
		}

		else
		{
			Message message;
			message._recipient = _recipient;
			message._sender = _sender;
			std::cout << "������� ���������:\n";
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
	std::cout << "������� ��������� ���������:\n";
	message.setMessage();
	allMessage.push_back(message);
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
				std::cout << "� ��� ���� ����� ������ ���������" << ": ";
			}
			cout << "\n�����������: " << it->_sender << endl <<
				"����������: " << it->_recipient << endl <<
				"���������: " << it->_message << endl;
		}
	}
	if (count!=0)
	{
		std::cout << "\n------------------------------------------------------\n";
		deleteMessage(recipient);
	}
	count = 0;
	for (vector<Message>::iterator it = allMessage.begin(); it < allMessage.end(); it++)
	{
		if (it->_recipient == "all" && recipient!=it->_sender)
		{
			count++;
			if (count == 1)
			{
				std::cout << "\n------------------------------------------------------\n";
				std::cout << "� ��� ���� ����� ����� ���������" << ": ";
			}
			cout << "\n�����������: " << it->_sender << endl <<
				"���������: " << it->_message << endl;
		}
	}
	if (count!=0)
	{
		std::cout << "\n------------------------------------------------------\n";
	}
}

void Chat::deleteMessage(std::string recipient)
{
	for (vector<Message>::iterator it = allMessage.begin(); it < allMessage.end();)
	{
		if (it->_recipient == recipient)
		{
			it = allMessage.erase(it);
		}
		else
			++it;
	}
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
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
				user = *result;
				std::cout << "������� ������: \n";
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
			cout << "����������� ������ ������������\n";
			Users user;
			user.setUser();
			vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
			if (result != allUsers.end())
			{
				cout << "\n������������ � ����� ������� ��� ����������!\n������ ��������� �������?(y/n)\n";
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
	message._sender = _login;
	std::cout << "������� ��������� ���������:\n";
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
				std::cout << "� ��� ���� ����� ����� ���������" << ": ";
			}
			cout << "\n�����������: " << it->_sender << endl <<
				"���������: " << it->_message << endl;
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
		cout << "\n�����������: " << it->_sender << endl <<
			"����������: " << it->_recipient << endl <<
			"���������: " << it->_message << endl;
	}
	cout << endl;
}

void Chat::start()
{
	char c = 'y'; // ������� ������ �� �����
	while (c == 'y')
	{
		registration();
		cout << "\n������ ���������������� ��� ������ ������������?" << endl;
		cin >> c;
		cout << endl;
	}

	enter(); // �����������
	c = 'y';
	while (c != 'n')
	{
		if (getstatus()) // ��������� ��� �� �������� ����
		{
			char message;
			cout << "\n������ ��������� ���������?(y/n)\n";
			cin >> c;

			if (c == 'y')
			{
				cout << "\n�������� ��� ������������� ���������: 1-private, 2-public\n";
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
					cout << "������������ ����!";
					break;
				}
			}
			if (c == 'n')
			{
				cout << "\n������ ��������� ���� ��� ������ ������� �������?(y/n)\n";
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
			cout << "���� �� ��������!\n";
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
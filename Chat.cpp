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
			std::cout << "\n����������� ������ ������������\n";
			Users user;
			user.setUser();
			vector<Users>::iterator result = find(allUsers.begin(), allUsers.end(), user);
			if (result != allUsers.end())
			{
				std::cout << "������������ � ����� ������� ��� ����������!\n������ ��������� �������?(y/n)";
				std::cin >> c;
			}
			else
			{
				allUsers.push_back(user);
				c = 'n';
			}
		}
}

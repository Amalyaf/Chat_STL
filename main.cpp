#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Chat chat;
	char c = 'y'; // ������� ������ �� �����
	while (c == 'y')
	{
		chat.registration();
		cout << "\n������ ���������������� ��� ������ ������������?" << endl;
		cin >> c;
		cout << endl;
	}

	chat.enter(); // �����������
	c = 'y';
	while (c != 'n')
	{
		if (chat.getstatus()) // ��������� ��� �� �������� ����
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
					chat.sendPrivateMessage();
					break;
				case '2':
					chat.sendPublicMessage();
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
					chat.exit();
					chat.enter();
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
	chat.printAllMessage();
}
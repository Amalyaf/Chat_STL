#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Chat chat;
	char contin = 'y';
	while (contin == 'y')
	{
		chat.registration();
		cout << "\n������ ���������������� ��� ������ ������������?" << endl;
		cin >> contin;
		cout << endl;
	}

	chat.getChat();
}
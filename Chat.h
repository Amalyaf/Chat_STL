#pragma once
#include <vector>
#include "Users.h"

class Chat
{
private:
	std::vector<Users> allUsers; // ��� ������������������ ������������
	std::string _recipient; //���������� ���������
	std::string _sender; // ����������� ���������
	std::string _login; // ����� ��������������� ������������
	std::string _password; // ������ ��������������� ������������
	bool _status = false; // ���� ��� �������� ���� ������ = true, � ��������� ������ - false.
public:
	Chat(); // �����������
	~Chat()=default; // ����������
	void getChat(); // ����� ������� ������ ������������
	void enter(); // ����������� ������������
	void setUser();
	void registration(); //  ����������� ������������
	void sendPrivateMessage(); // �������� ������ ���������
	void sendPublicMessage(); // �������� ��������� ���������
	bool getstatus(); // ����� ������� ������ ����������� (_status)
	void exit(); // ����������� ��������������� ������������
};

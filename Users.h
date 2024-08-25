#pragma once
#include <iostream>

class Users
{
private:
	std::string _password; // ������
	std::string _name; // ���

public:
	std::string _login; // �����
	Users(); // �����������
	~Users() = default;// ����������
	void setUser(); // ����� ����������� ������ ������������
	std::string getLogin(); // ����� ���������� ����� ������������
	std::string getPassword(); // ����� ���������� ������ ������������
	std::string getName(); // ����� ���������� ��� ������������
	friend std::ostream& operator<<(std::ostream& output, const Users& user); // ���������� ��������� ������
	bool operator==(const Users& user); // ���������� ��������� ������
};
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <Windows.h>

using namespace std;

//���������� ��� Ŭ����.
// ���� �� �ڵ�� ��������ݿ� ���н�, ���̵� ������ �������� �ܾ׺����� �������� ���оȵ�

class acc_INFO
{
private:
	int id;
	int money;
	char* name;
	//static int acc_num;
public:
	acc_INFO(int Id, int Money, char* Name) :id(Id), money(Money)
	{	
		int len = strlen(Name) + 1;
		name = new char[len];
		strcpy(name,Name);
	}

	~acc_INFO()
	{
		delete[]name;
	}

	bool DepositMony(int id,int money)
	{
		if (this->id == id)
		{
			this->money += money;
			return true;
		}
		return false;
	}
	bool WithdrawMony(int id, int money)
	{
		if (this->id == id)
		{
			this->money -= money;
			if (this->money < 0)
			{
				return false;
			}
			return true;
		}
		return false;
	}

	void ShowAllAccInfo()
	{
		cout << "====================" << endl;
		cout << "[ �� �� ID ] " << id << endl;

		cout << "[ ��   �� ] " << name << endl;

		cout << "[ ��   �� ]" << money << endl;
	}

};
//int acc_INFO::acc_num = 0;
acc_INFO* acc_arr[100];
int acc_num = 0;

enum { EXIT = 0, MAKE, DEPOSIT, WITHDRAW, ALLACC };

void showMenew();
void MakeAccount();
void DepositMony();
void WithdrawMony();
void ShowAllAccInfo();


int main()
{
	//main page
	int choose;

	while (true)
	{
		showMenew();
		cin >> choose;
		switch (choose)
		{
			case MAKE:
				MakeAccount();
				break;
			case DEPOSIT:
				DepositMony();
				break;
			case WITHDRAW:
				WithdrawMony();
				break;
			case ALLACC:
				ShowAllAccInfo();
				break;
			case EXIT:
				return 0;
			default:
				cout << "Rwong Num" << endl;
				break;
		}
	}


	return 0;
}
void showMenew()
{
	cout << "------- Main -------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "0. ���α׷� ����" << endl;
}
void MakeAccount()
{
	int id;
	char name[20];
	int money;
	cout << "���¸� �����մϴ�." << endl;
	cout << "[ �� �� ID ] ";
	cin >> id;
	cout << endl;

	cout << "[ ��   �� ] ";
	cin >> name;
	cout << endl;

	cout << "[ ��   �� ]";
	cin >> money;

	acc_arr[acc_num++] = new acc_INFO(id, money, name);
}

void DepositMony()
{
	int id;
	int money;
	

	cout << "������ �Ա��մϴ�" << endl;
	cout << "[ �� �� ID ] ";
	cin >> id;
	cout << "[ �Ա� �ݾ� ]";
	cin >> money;

	for (int i = 0; i < acc_num; i++)
	{
		if (acc_arr[i]->DepositMony(id, money) == true)
			break;
		else
		{
			cout << "�Աݿ� ����" << endl;
		}
	}

	


}

void WithdrawMony()
{
	int id;
	int money;
	int i = 0;

	cout << "������ ��� �մϴ�" << endl;
	cout << "[ �� �� ID ] ";
	cin >> id;
	cout << "[ ��� �ݾ� ]";
	cin >> money;

	for (int i = 0; i < acc_num; i++)
	{
		if (acc_arr[i]->DepositMony(id, money) == true)
			break;
		else
		{
			cout << "�Ǽӳ�" << endl;
		}
	}
	
}

void ShowAllAccInfo()
{
	for (int i = 0; i < acc_num; i++)
	{
		acc_arr[i]->ShowAllAccInfo();
	}
}
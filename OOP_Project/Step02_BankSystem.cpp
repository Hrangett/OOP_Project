#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <Windows.h>

using namespace std;

//계좌정보를 담는 클래스.
// 지금 이 코드는 계좌입출금에 실패시, 아이디 오류의 문제인지 잔액부족의 문제인지 구분안됨

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
		cout << "[ 계 좌 ID ] " << id << endl;

		cout << "[ 이   름 ] " << name << endl;

		cout << "[ 잔   액 ]" << money << endl;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "0. 프로그램 종료" << endl;
}
void MakeAccount()
{
	int id;
	char name[20];
	int money;
	cout << "계좌를 개설합니다." << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> id;
	cout << endl;

	cout << "[ 이   름 ] ";
	cin >> name;
	cout << endl;

	cout << "[ 잔   액 ]";
	cin >> money;

	acc_arr[acc_num++] = new acc_INFO(id, money, name);
}

void DepositMony()
{
	int id;
	int money;
	

	cout << "예금을 입금합니다" << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> id;
	cout << "[ 입금 금액 ]";
	cin >> money;

	for (int i = 0; i < acc_num; i++)
	{
		if (acc_arr[i]->DepositMony(id, money) == true)
			break;
		else
		{
			cout << "입금에 실패" << endl;
		}
	}

	


}

void WithdrawMony()
{
	int id;
	int money;
	int i = 0;

	cout << "예금을 출금 합니다" << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> id;
	cout << "[ 출금 금액 ]";
	cin >> money;

	for (int i = 0; i < acc_num; i++)
	{
		if (acc_arr[i]->DepositMony(id, money) == true)
			break;
		else
		{
			cout << "또속냐" << endl;
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
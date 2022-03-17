/*
	은행계좌 프로그램 01
	- 기능 1. 계좌 개설
	- 기능 2. 입     금
	- 기능 3. 출     금
	- 기능 4. 전체고객 잔액 조회

	- 통장의 계좌번호는 중복되지 않는다 가정
	- 입금 및 출금액은 무조건 0보다 크다
	- 고객의 졔좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 세가지만 저장 및 관리한다.
	- 둘 이상의 고객정보를 저장을 위해 배열을 사용
	- 계좌번호는 정수

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

typedef struct _acc_info {
	int id;
	char name[20];
	int money;
}ACC_INFO;

ACC_INFO acc_arr[100];
int acc_num = 0;

void MakeAccount();
void DepositMony();
void WithdrawMony();
void ShowAllAccInfo();


int main()
{
	int choose;
	while (1) {
		//system("cls");
		cout << "------- Main -------" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입     금" << endl;
		cout << "3. 출     금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "0. 프로그램 종료" << endl;

		cout << "---> ";
		cin >> choose;
		cout << endl;
		switch (choose) {
		case 1:
			//계좌개설
			MakeAccount();

			break;

		case 2:
			//입금
			DepositMony();

			break;

		case 3:
			//출금
			WithdrawMony();
			break;
		case 4:
			//계좌정보 전체 출력
			ShowAllAccInfo();
			break;

		case 0:
			//프로그램 종료
			return 0;

		default:
			cout << "잘못된 숫자를 입력하였..." << endl << endl;
		}
			

	}

	

	return 0;

}

void MakeAccount()
{
	/*
		-통장의 계좌번호는 중복되지 않는다 가정
		- 입금 및 출금액은 무조건 0보다 크다
		- 고객의 졔좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 세가지만 저장 및 관리한다.
		- 둘 이상의 고객정보를 저장을 위해 배열을 사용
		- 계좌번호는 정수
	*/

	

	cout << "계좌를 개설합니다." << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> acc_arr[acc_num].id;
	cout << endl;

	cout << "[ 이   름 ] ";
	cin >> acc_arr[acc_num].name;
	cout << endl;

	cout << "[ 잔   액 ]";
	cin >> acc_arr[acc_num].money;

	acc_num++;




}

void DepositMony()
{
	/*
		-통장의 계좌번호는 중복되지 않는다 가정
		- 입금 및 출금액은 무조건 0보다 크다
		- 고객의 졔좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 세가지만 저장 및 관리한다.
		- 둘 이상의 고객정보를 저장을 위해 배열을 사용
		- 계좌번호는 정수
	*/
	int i = 0;
	ACC_INFO Depos;

	cout << "예금을 입금합니다." << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> Depos.id;
	cout << endl;

	cout << "[ 잔   액 ]";
	cin >> Depos.money;
	cout << endl;

	while (true)
	{
		acc_arr[i];
		if (acc_arr[i].id == Depos.id)
		{
			acc_arr[i].money += Depos.money;
			cout << "입금완료";
			break;
		}
		i++;
	}

}

void WithdrawMony()
{
	/*
		-통장의 계좌번호는 중복되지 않는다 가정
		- 입금 및 출금액은 무조건 0보다 크다
		- 고객의 졔좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 세가지만 저장 및 관리한다.
		- 둘 이상의 고객정보를 저장을 위해 배열을 사용
		- 계좌번호는 정수
	*/
	int i = 0;
	ACC_INFO With;

	cout << "예금을 출금 합니다." << endl;
	cout << "[ 계 좌 ID ] ";
	cin >> With.id;
	cout << endl;

	cout << "[ 잔   액 ]";
	cin >> With.money;
	cout << endl;

	while (true)
	{
		acc_arr[i];
		if (acc_arr[i].id == With.id)
		{
			acc_arr[i].money -= With.money;
			cout << "출금완료";
			break;
		}
		i++;
	}
}

void ShowAllAccInfo()
{
	/*
		-통장의 계좌번호는 중복되지 않는다 가정
		- 입금 및 출금액은 무조건 0보다 크다
		- 고객의 졔좌정보는 계좌번호, 고객이름, 고객의 잔액 이렇게 세가지만 저장 및 관리한다.
		- 둘 이상의 고객정보를 저장을 위해 배열을 사용
		- 계좌번호는 정수
	*/
	int i = 0;

	cout << "계좌정보.." << endl;
	while (true)
	{
		cout << "[ 계 좌 ID ] " << acc_arr[i].id << endl;

		cout << "[ 이   름 ] " << acc_arr[i].name << endl;

		cout << "[ 잔   액 ]" << acc_arr[i].money;
		if (i == acc_num)
		{
			cout << "출력을 종료,,";
			break;
		}
		i++;
	}

}
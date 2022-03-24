#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <Windows.h>
void AccountHandler::ShowMenu(void)const
{
	cout << "------- Main -------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입     금" << endl;
	cout << "3. 출     금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "0. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{

	int sel;
	cout << "[ 계 좌 종 류  선 택 ]" << endl;
	cout << " 1. 보 통 예 금 계 좌" << endl;
	cout << " 2. 신 용 선 택 계 좌" << endl;
	cout << " -- > ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else 
		MakeCreditAccount();


}

void AccountHandler::MakeNormalAccount()
{
	
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통 예금 계좌 개설]" << endl;
	cout << "계좌ID :";
	cin >> id;

	cout << "이름 :";
	cin >> name;

	cout << "입금액 :";
	cin >> balance;
	
	cout << "이자율 :";
	cin >> interRate;
	cout << endl;
	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[ 신용 계좌 개설 ]" << endl;
	cout << "계좌ID :";
	cin >> id;

	cout << "이름 :";
	cin >> name;

	cout << "입금액 :";
	cin >> balance;

	cout << "이자율 :";
	cin >> interRate;

	cout << "신용등급(1 to a, 2 to b, 3 to C): ";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{

	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;

	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;

	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;

	default:
		break;
	}

}

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID :";
	cin >> id;

	cout << "입금 액 :";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;

}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID :";
	cin >> id;

	cout << "출금 액 :";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl << endl;

}

AccountHandler::AccountHandler():accNum(0)
{}

void AccountHandler::ShowAllAccInfo()const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}
#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include <Windows.h>
void AccountHandler::ShowMenu(void)const
{
	cout << "------- Main -------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��     ��" << endl;
	cout << "3. ��     ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "0. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{

	int sel;
	cout << "[ �� �� �� ��  �� �� ]" << endl;
	cout << " 1. �� �� �� �� �� ��" << endl;
	cout << " 2. �� �� �� �� �� ��" << endl;
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

	cout << "[���� ���� ���� ����]" << endl;
	cout << "����ID :";
	cin >> id;

	cout << "�̸� :";
	cin >> name;

	cout << "�Աݾ� :";
	cin >> balance;
	
	cout << "������ :";
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

	cout << "[ �ſ� ���� ���� ]" << endl;
	cout << "����ID :";
	cin >> id;

	cout << "�̸� :";
	cin >> name;

	cout << "�Աݾ� :";
	cin >> balance;

	cout << "������ :";
	cin >> interRate;

	cout << "�ſ���(1 to a, 2 to b, 3 to C): ";
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
	cout << "[�� ��]" << endl;
	cout << "����ID :";
	cin >> id;

	cout << "�Ա� �� :";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;

}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID :";
	cin >> id;

	cout << "��� �� :";
	cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;

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
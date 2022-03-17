/*
	������� ���α׷� 01
	- ��� 1. ���� ����
	- ��� 2. ��     ��
	- ��� 3. ��     ��
	- ��� 4. ��ü�� �ܾ� ��ȸ

	- ������ ���¹�ȣ�� �ߺ����� �ʴ´� ����
	- �Ա� �� ��ݾ��� ������ 0���� ũ��
	- ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� �������� ���� �� �����Ѵ�.
	- �� �̻��� �������� ������ ���� �迭�� ���
	- ���¹�ȣ�� ����

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
		cout << "1. ���°���" << endl;
		cout << "2. ��     ��" << endl;
		cout << "3. ��     ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "0. ���α׷� ����" << endl;

		cout << "---> ";
		cin >> choose;
		cout << endl;
		switch (choose) {
		case 1:
			//���°���
			MakeAccount();

			break;

		case 2:
			//�Ա�
			DepositMony();

			break;

		case 3:
			//���
			WithdrawMony();
			break;
		case 4:
			//�������� ��ü ���
			ShowAllAccInfo();
			break;

		case 0:
			//���α׷� ����
			return 0;

		default:
			cout << "�߸��� ���ڸ� �Է��Ͽ�..." << endl << endl;
		}
			

	}

	

	return 0;

}

void MakeAccount()
{
	/*
		-������ ���¹�ȣ�� �ߺ����� �ʴ´� ����
		- �Ա� �� ��ݾ��� ������ 0���� ũ��
		- ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� �������� ���� �� �����Ѵ�.
		- �� �̻��� �������� ������ ���� �迭�� ���
		- ���¹�ȣ�� ����
	*/

	

	cout << "���¸� �����մϴ�." << endl;
	cout << "[ �� �� ID ] ";
	cin >> acc_arr[acc_num].id;
	cout << endl;

	cout << "[ ��   �� ] ";
	cin >> acc_arr[acc_num].name;
	cout << endl;

	cout << "[ ��   �� ]";
	cin >> acc_arr[acc_num].money;

	acc_num++;




}

void DepositMony()
{
	/*
		-������ ���¹�ȣ�� �ߺ����� �ʴ´� ����
		- �Ա� �� ��ݾ��� ������ 0���� ũ��
		- ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� �������� ���� �� �����Ѵ�.
		- �� �̻��� �������� ������ ���� �迭�� ���
		- ���¹�ȣ�� ����
	*/
	int i = 0;
	ACC_INFO Depos;

	cout << "������ �Ա��մϴ�." << endl;
	cout << "[ �� �� ID ] ";
	cin >> Depos.id;
	cout << endl;

	cout << "[ ��   �� ]";
	cin >> Depos.money;
	cout << endl;

	while (true)
	{
		acc_arr[i];
		if (acc_arr[i].id == Depos.id)
		{
			acc_arr[i].money += Depos.money;
			cout << "�ԱݿϷ�";
			break;
		}
		i++;
	}

}

void WithdrawMony()
{
	/*
		-������ ���¹�ȣ�� �ߺ����� �ʴ´� ����
		- �Ա� �� ��ݾ��� ������ 0���� ũ��
		- ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� �������� ���� �� �����Ѵ�.
		- �� �̻��� �������� ������ ���� �迭�� ���
		- ���¹�ȣ�� ����
	*/
	int i = 0;
	ACC_INFO With;

	cout << "������ ��� �մϴ�." << endl;
	cout << "[ �� �� ID ] ";
	cin >> With.id;
	cout << endl;

	cout << "[ ��   �� ]";
	cin >> With.money;
	cout << endl;

	while (true)
	{
		acc_arr[i];
		if (acc_arr[i].id == With.id)
		{
			acc_arr[i].money -= With.money;
			cout << "��ݿϷ�";
			break;
		}
		i++;
	}
}

void ShowAllAccInfo()
{
	/*
		-������ ���¹�ȣ�� �ߺ����� �ʴ´� ����
		- �Ա� �� ��ݾ��� ������ 0���� ũ��
		- ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �̷��� �������� ���� �� �����Ѵ�.
		- �� �̻��� �������� ������ ���� �迭�� ���
		- ���¹�ȣ�� ����
	*/
	int i = 0;

	cout << "��������.." << endl;
	while (true)
	{
		cout << "[ �� �� ID ] " << acc_arr[i].id << endl;

		cout << "[ ��   �� ] " << acc_arr[i].name << endl;

		cout << "[ ��   �� ]" << acc_arr[i].money;
		if (i == acc_num)
		{
			cout << "����� ����,,";
			break;
		}
		i++;
	}

}
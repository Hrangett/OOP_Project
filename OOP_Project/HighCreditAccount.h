#ifndef __HIGHCREDIT__ACCOUNT_H__
#define __HIGHCREDIT__ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;
public:
	HighCreditAccount(int ID, int money, const char* name, int rate, int special) :NormalAccount(ID, money, name, rate), specialRate(special) {}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);	//원금과 이자 추가
		Account::Deposit(money * (specialRate / 100.0));	//특별 이자 추가
	}


};

#endif // !__HIGHCREDIT__ACCOUNT_H__


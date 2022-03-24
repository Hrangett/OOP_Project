#include"BankingCommonDecl.h"
#include"AccountArray.h"

BoundCheckAccointPtrArray::BoundCheckAccointPtrArray(int len) :arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccointPtrArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception.." << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccointPtrArray::operator[](int idx)const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception.." << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckAccointPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccointPtrArray:: ~BoundCheckAccointPtrArray()
{
	delete[]arr;
}
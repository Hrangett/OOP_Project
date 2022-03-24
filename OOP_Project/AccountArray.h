#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"

typedef Account* ACCOUNT_PTR;

class BoundCheckAccointPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccointPtrArray(const BoundCheckAccointPtrArray& arr) {}
	BoundCheckAccointPtrArray& operator=(const BoundCheckAccointPtrArray& arr) {}

public:
	BoundCheckAccointPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccointPtrArray();

};

#endif // !__ACCOUN_ARRAY_H__

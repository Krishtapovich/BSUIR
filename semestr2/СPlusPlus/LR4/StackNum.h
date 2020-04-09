//---------------------------------------------------------------------------
#ifndef StackNumH
#define StackNumH
#include "NodeNum.h"
class StackNum
{
public:
	NodeNum *pHead, *pTail;
	int size;
	StackNum();
	void Add(float n);
	float GetBack();
	float Delete();
};
//---------------------------------------------------------------------------
#endif

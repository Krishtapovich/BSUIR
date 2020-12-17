//---------------------------------------------------------------------------
#include "NodeOp.h"
#ifndef StackOpH
#define StackOpH
class StackOp
{
public:
	NodeOp *pHead, *pTail;
	int size;
	StackOp();
	void Add(char c);
    char GetBack();
	char Delete();
};
//---------------------------------------------------------------------------
#endif

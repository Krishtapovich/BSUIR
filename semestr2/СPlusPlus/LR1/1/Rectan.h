//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef RectanH
#define RectanH
class Rectan
{
public:
	int x1, y1, x2, y2;
	Rectan(int x1, int y1, int x2, int y2);
	virtual void Show(TCanvas *Canvas, TColor C);
	void Move(TCanvas *Canvas);
	void MoveX(TCanvas* Canvas, TColor C);
};
//---------------------------------------------------------------------------
#endif

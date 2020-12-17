//---------------------------------------------------------------------------

#pragma hdrstop

#include "Circ.h"
#include "Rectan.h"
Circ::Circ(int x1, int y1, int x2, int y2):Rectan(x1, y1, x2, y2)
{
}
void Circ::Show(TCanvas *Canvas, TColor C)
{
   Canvas->Brush->Color = C;
   Canvas->Pen->Color = C;
   Canvas->Ellipse(x1, y1, x2, y2);
}
void Circ::Move(TCanvas *Canvas)
{
	Rectan::Move(Canvas);
}
void Circ::MoveX(TCanvas *Canvas, TColor C)
{
	Rectan::MoveX(Canvas, C);
}
void Circ::MoveDown(TCanvas *Canvas, TColor C)
{
   y1 += 10;
   y2 += 10;
   Show(Canvas, C);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

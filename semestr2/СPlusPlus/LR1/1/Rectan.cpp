//---------------------------------------------------------------------------

#pragma hdrstop

#include "Rectan.h"
	Rectan::Rectan(int x1, int y1, int x2, int y2)
	{
	   this->x1 = x1;
	   this->y1 = y1;
	   this->x2 = x2;
	   this->y2 = y2;
	}

	void Rectan::Show(TCanvas *Canvas, TColor C)
   {
		Canvas->Brush->Color = C;
		Canvas->Pen->Color = C;
		Canvas->Rectangle(x1, y1, x2, y2);
   }

   void Rectan::Move(TCanvas *Canvas)
   {
	   x1 += 10;
	   y1 += 10;
	   x2 += 10;
	   y2 += 10;
   }

  void Rectan::MoveX(TCanvas *Canvas, TColor C)
   {
	   x2 += 10;
	   x1 += 10;
	   Show(Canvas, C);
   }
//---------------------------------------------------------------------------
#pragma package(smart_init)

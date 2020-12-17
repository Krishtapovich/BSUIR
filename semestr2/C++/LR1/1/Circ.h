//---------------------------------------------------------------------------
#include <vcl.h>
#include "Rectan.h"
#ifndef CircH
#define CircH
class Circ:public Rectan
{
public:
   Circ(int x1, int y1, int x2, int y2);
   void Show(TCanvas *Canvas, TColor C);
   void Move(TCanvas *Canvas);
   void MoveX(TCanvas* Canvas, TColor C);
   void MoveDown(TCanvas * Canvas, TColor C);
};
//---------------------------------------------------------------------------
#endif

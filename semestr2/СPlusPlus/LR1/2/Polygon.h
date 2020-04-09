//---------------------------------------------------------------------------
#ifndef PolygonH
#include <vcl.h>
#include <Math.h>
#define PolygonH
class Polygon
{
public:
	virtual void Draw();
	virtual int Square();
	virtual int Perimetr();
	virtual void MassCenter();
	virtual void Move();
	virtual void Hide();
	virtual void Resize();
	virtual void MoveMC();
	virtual void DxDy();
	virtual void Show();
	virtual void Rotate();
    virtual void HideRotate();
};
//---------------------------------------------------------------------------
#endif

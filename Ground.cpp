#include "Ground.h"

Ground::Ground(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo); //update to draw resistor

}

void Ground::Operate()
{

}
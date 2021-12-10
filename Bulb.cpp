#include "Bulb.h"

Bulb::Bulb(GraphicsInfo *b_GfxInfo):Component(b_GfxInfo)
{}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, Selected); //update to draw resistor

}

void Bulb::Operate()
{

}
string Bulb::CompData()
{
	return "Bulb";
}
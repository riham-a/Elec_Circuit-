#include "Battery.h"
Battery::Battery(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo); //update to draw resistor

}

void Battery::Operate()
{

}
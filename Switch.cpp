#include "Switch.h"

Switch::Switch(GraphicsInfo* s_GfxInfo):Component(s_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo); //update to draw resistor

}

void Switch::Operate()
{

}
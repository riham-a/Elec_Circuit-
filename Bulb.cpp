#include "Bulb.h"
#include <fstream>


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
	pUI->DrawBulb(*m_pGfxInfo); //update to draw resistor
}

void Bulb::Save(fstream file)
{
	file << "BLB" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;

}

void Bulb::Operate()
{

}
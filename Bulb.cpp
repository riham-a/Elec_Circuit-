#include "Bulb.h"
#include <fstream>


Bulb::Bulb(GraphicsInfo *b_GfxInfo):Component(b_GfxInfo)
{}
Bulb::Bulb(GraphicsInfo* b_GfxInfo, int on_of) : Component(b_GfxInfo)
{
	on_off = on_of;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo, on_off, Selected); //update to draw resistor
}

void Bulb::Operate()
{

}
string Bulb::CompData()
{
	return "Bulb";
}

void Bulb::Save(fstream file)
{
	file << "BLB" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;

}

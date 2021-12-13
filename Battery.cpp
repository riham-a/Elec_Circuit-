#include "Battery.h"
#include <fstream>
Battery::Battery(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, Selected); //update to draw resistor


}

void Battery::Operate()
{
}
string Battery::CompData()
{
	return "Battery";
	pUI->DrawBattery(*m_pGfxInfo); //update to draw resistor
}

void Battery::Save(fstream file)
{
	file << "BAT" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;
}

void Battery::Operate()
{

}
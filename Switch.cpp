#include "Switch.h"
#include <fstream>


Switch::Switch(GraphicsInfo* s_GfxInfo):Component(s_GfxInfo)
{}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, Selected); //update to draw resistor


}

void Switch::Operate()
{

}
string Switch::CompData()
{
	return "Switch";
	pUI->DrawSwitch(*m_pGfxInfo); //update to draw resistor

}

void Switch::Save(fstream file)
{
	file << "SWT" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) << endl;

}

void Switch::Operate()
{

}
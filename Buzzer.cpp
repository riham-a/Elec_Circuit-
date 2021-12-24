#include "Buzzer.h"
#include <fstream>

Buzzer::Buzzer(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo, Selected); //update to draw resistor


}

void Buzzer::Operate()
{

}
string Buzzer::CompData()
{
	return "Buzzer";
	//pUI->DrawBuzzer(*m_pGfxInfo); //update to draw resistor

}

void Buzzer::Save(fstream file)
{
	file << "BUZ" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) << endl;

}

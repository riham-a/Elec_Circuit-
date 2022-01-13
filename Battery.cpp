#include "Battery.h"
Battery::Battery(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.

	pUI->DrawBattery(*m_pGfxInfo, selected); //update to draw resistor

}

void Battery::Operate()
{
}
string Battery::CompData()
{
	return "Battery";
}

Component* Battery::Copycomponent(GraphicsInfo* ginfo)
{
	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
	Component* R = new Battery(ginfo);
//	R->setCompName(m_Label); R->setCompValue(c_Value);
	return  R;
}

//=======
//	Component* c = nullptr;
//	return c;
//}

//void Battery::Save(fstream file)
//{
//	file << "BAT" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;
//	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
//	Component* R = new Battery(ginfo);
////	R->setCompName(m_Label); R->setCompValue(c_Value);
//	return  R;
//}

void Battery::Save(ofstream *file)
{
	*file << "BAT" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;
}
#include "Ground.h"
#include <fstream>


Ground::Ground(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, Selected); //update to draw resistor

}

void Ground::Operate()
{

}
string Ground::CompData()
{
	return "Ground";

}

Component* Ground::Copycomponent(GraphicsInfo* ginfo)
{
	Component* R = new Ground(ginfo);
	return  R;
}

void Ground::Save(ofstream *file)
{
	*file << "GRD" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;

}

#include "Fuse.h"
#include <fstream>

Fuse::Fuse(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.


	pUI->DrawFuse(*m_pGfxInfo, Selected); //update to draw resistor

}

void Fuse::Save(ofstream *file)
{
	*file << "FUS" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y)<< endl;

}

Component* Fuse::Copycomponent(GraphicsInfo* ginfo)
{
	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
	Component* R = new Fuse(ginfo);
//	R->setCompName(m_Label); R->setCompValue(c_Value);
	return  R;
}

void Fuse::Operate()
{


}
string Fuse::CompData()
{
	return "Fuse";

}
#include "Module.h"
#include <fstream>
Module::Module(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Module::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawModule(*m_pGfxInfo, Selected); //update to draw resistor


}

void Module::Operate()
{
}
string Module::CompData()
{
	return "Module";
}

void Module::Save(fstream file)
{
	file << "MOD" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) << endl;

}
void Module::Load()
{

 }
 void Module::Save(ofstream* file)
{

}
Component* Module::Copycomponent(GraphicsInfo* ginfo)
{
	Component* c = nullptr;
	return c;
 }

#include "Fuse.h"

Fuse::Fuse(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Fuse::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFuse(*m_pGfxInfo, Selected); //update to draw resistor

}

void Fuse::Operate()
{

}
string Fuse::CompData()
{
	return "Fuse";
}
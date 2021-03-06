#include "Connection.h"


Connection::Connection(GraphicsInfo *r_GfxInfo, Component *cmp1, Component *cmp2)
{
	pGfxInfo = r_GfxInfo;
	Cmpnt1 = cmp1;
	Cmpnt2 = cmp2;
	selected = false;
}
void Connection::Draw(UI* pUI)
{
	pUI->DrawConnection(*pGfxInfo, selected);
}

GraphicsInfo* Connection::getC_pGfxInfo()
{
	return pGfxInfo;
}

void Connection::setConnName(string s)
{
	con_Label = s;
}

void Connection::setComp1(Component *comp1)
{ 
	Cmpnt1 = comp1;
}

void Connection::setComp2(Component *comp2)
{
	Cmpnt2 = comp2;
}

void Connection::Savecon(ofstream *file)
{
//	Cmpnt1->GetID();
	*file << to_string(Cmpnt1->GetID()) << " " << to_string(Cmpnt1->GetID()) << endl; // I need the Id 
}
bool  Connection::ifSelected()
{
	return selected;
}
void  Connection::setSelected(bool sel)
{
	selected = sel;
}



#include "Component.h"
#include <fstream>

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	ID = SID++;
}

int Component::SID = 1;

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;

}

GraphicsInfo* Component::getM_pGfxInfo()
{
	return m_pGfxInfo;
}
void Component::setSelected(bool select)
{
	selected = select;
}

void Component::setCompName(string s)
{
	m_Label = s;
}

void Component::setCompValue(double n)
{
	c_Value = n;
}

string Component::GetName()
{
	return m_Label;
}

double Component::GetValue()
{
	return c_Value;
}

string Component::Getcomptype()
{
	return comptype;
}

void Component::Save(fstream *file)
{
	// comptype, num, m_label, c_value, graphics info
	*file << "comptype" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " <<to_string(getM_pGfxInfo()->PointsList[0].y) << endl;
}

int Component::GetID()
{
	return ID;
}

void Component::Load()
{
}



Component::~Component()
{}



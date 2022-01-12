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

bool Component::IFSelected()
{
	return Selected;
}
void Component::setSelected(bool s)
{
	Selected = s;
}
GraphicsInfo* Component::getM_pGfxInfo()
{
	return m_pGfxInfo;
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


int Component::GetID()
{
	return ID;
}

void Component::Load()
{
}
//Component* Component::Copycomponent()
//{
//	return nullptr;
//}
///////////////////////////////////////////////////Riham
bool Component::AddtoConnectionsTerm1(Connection* pC)
{
	if (term1_conn_count == MAX_CONNS)
		return false;
	else
		term1_conn_count++;
		term1_connections[term1_conn_count] = pC;
		return true;
}
////////////////////////////////////////////
bool Component::AddtoConnectionsTerm2(Connection* pC)
{
	if (term2_conn_count == MAX_CONNS)
		return false;
	else
	{
		term2_connections[term1_conn_count++] = pC;
		return true;
	}
}
bool Component::returnTerr1(Point* P)
{
	if (this)
	{
		if ((P->x >= m_pGfxInfo->PointsList[0].x) && (P->x <= m_pGfxInfo->PointsList[1].x))
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Component::returnTerr2(Point* P)
{
	if (this)
	{
		if ((P->x > this->m_pGfxInfo->PointsList[0].x) && (P->x < this->m_pGfxInfo->PointsList[1].x))
			return true;
		else
			return false;
	}
	else
		return false;
}

void  Component::deleteComp_Conns()
{
	for (int i = 0; i < term1_conn_count; i++)
	{
		if (term1_connections[i])
			delete term1_connections[i];
	}
	for (int i = 0; i < term2_conn_count; i++)
	{
		if (term2_connections[i])
			delete term2_connections[i];
	}

}
Component::~Component()
{}



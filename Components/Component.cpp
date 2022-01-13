#include "Component.h"


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
	current = 0;
	volt = 0;

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

void Component::setvolt(double v)
{
	volt = v;

}

void Component::setcurrent(double c)
{
	current = c;
}

string Component::GetName()
{
	return m_Label;
}

double Component::GetValue()
{
	return c_Value;
}

double Component::Getcurrent()
{
	return current;
}

double Component::Getvolt()
{
	return volt;
}

string Component::Getcomptype()
{
	return comptype;
}
//void Component::Save(fstream *file)
//{
//	// comptype, num, m_label, c_value, graphics info
//	*file << "comptype" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " <<to_string(getM_pGfxInfo()->PointsList[0].y) << endl;
//}


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

int Component::gettermn1()
{
	return term1_conn_count;
}

int Component::gettermn2()
{
	return term2_conn_count;
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
double Component::getTerm1_volt()
{
	return term1_volt;
}
double Component::getTerm2_volt()
{
	return term2_volt;
}
//void Component::setvolt(ApplicationManager* aptr)
//{
//
//	if (MODE::SIMULATION)
//	{
//		//volt = (current * (aptr->GetSelected->GetValue()));
//		volt = 0;
//	}
//	else
//	{
//		volt = 0;
//	}
//
//}
//
//void Component::setcurrent(ApplicationManager* aptr)
//{
//	int v = 0;
//	int rtotal = 0;
//
//	if (MODE::SIMULATION)
//	{
//		for (int i = 0; i < aptr->getCompCount(); i++)
//		{
//			if (aptr->getCompList()[i]->Getcomptype() == "Battery")
//			{
//				v = v + aptr->getCompList()[i]->GetValue();
//			}
//			else
//			{
//				rtotal = rtotal + aptr->getCompList()[i]->GetValue();
//			}
//
//		}
//
//		current = (v / rtotal);
//	}
//	else
//	{
//		current = 0;
//	}
//}
double Component::Getcurrent()
{
	return current;
}

double Component::Getvolt()
{
	return volt;
}
Component::~Component()
{}



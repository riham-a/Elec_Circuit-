#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
}

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
Component::~Component()
{}


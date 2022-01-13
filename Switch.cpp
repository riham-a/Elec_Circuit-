#include "Switch.h"

Switch::Switch(GraphicsInfo* s_GfxInfo) :Component(s_GfxInfo)
{
	on_off = 1;


}
Switch::Switch(GraphicsInfo* s_GfxInfo, int on_of) : Component(s_GfxInfo)
{
	on_off = on_of;

}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.

	pUI->DrawSwitch(*m_pGfxInfo, on_off, selected); //update to draw resistor

}

string Switch::CompData()
{
	return "Switch";
}

Component* Switch::Copycomponent(GraphicsInfo* ginfo)
{
	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
	Component* R = new Switch(ginfo);
	//R->setCompName(m_Label); R->setCompValue(c_Value);
	return  R;

}

int Switch::getON_OFF()
{
	return on_off;
}
void Switch::setON_OFF(int o_F)
{
	on_off = o_F;
}

//Component* Switch::Copycomponent(GraphicsInfo* ginfo)
//{
//	//GraphicsInfo* pGInfo = new GraphicsInfo(2);
//	Component* R = new Switch(ginfo);
//	//R->setCompName(m_Label); R->setCompValue(c_Value);
//	return  R;
//}
//
//=======
//>>>>>>> Riham
void Switch::Save(ofstream *file)
{
	*file << "SWT" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) << endl;

}

void Switch::Operate()
{

}
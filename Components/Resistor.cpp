#include "Resistor.h"

Resistor::Resistor(GraphicsInfo *r_GfxInfo):Component(r_GfxInfo)
{}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, selected); //update to draw resistor

}
//////////////////////////////////////////////
// Riham
 string Resistor::CompData()
{
	 return "Resistor";
}
 Component* Resistor::Copycomponent(GraphicsInfo* ginfo)
 {
	 //UI* pUI = pManager->GetUI();
	 // the same name 
	 // the same graphics info 
	 // the same value
	 //GraphicsInfo* pGInfo = new GraphicsInfo(2);
	 //Component* R = new Resistor(nullptr);
	 //R->setCompName(m_Label); R->setCompValue(c_Value);
	 //return  R;
	 Resistor* pR = new Resistor(ginfo);
	// pManager->AddComponent(pR); // paste 
	 return pR;
 }
 void Resistor::Save(ofstream *file)
 {
	 *file << "RES" << " " << to_string(ID) << " " << GetName() << " " << to_string(GetValue()) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) << endl;

 }
////////////////////////////////////////////////
void Resistor::Operate()
{

}
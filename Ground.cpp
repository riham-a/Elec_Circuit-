#include "Ground.h"

Ground::Ground(GraphicsInfo* b_GfxInfo) :Component(b_GfxInfo)
{}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo); //update to draw resistor

}

void Ground::Operate()
{

<<<<<<< Updated upstream
=======
}
string Ground::CompData()
{
	return "Ground";

}

void Ground::Save(fstream file)
{
	file << "GRD" << " " << to_string(ID) << " " << m_Label << " " << to_string(c_Value) << " " << to_string(getM_pGfxInfo()->PointsList[0].x) << " " << to_string(getM_pGfxInfo()->PointsList[0].y) <<endl;

}

int Ground::getGcount()
{
	return Groundcount;
}

void Ground::setGcount(int s)
{
	Groundcount = s;
>>>>>>> Stashed changes
}
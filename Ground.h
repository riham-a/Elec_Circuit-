#pragma once
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Components\Component.h"
class Ground :public Component
{
private:
	
public:
	static int Groundcount;
	int ground = -1;
	Ground(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(fstream file);
	static int getGcount();
	static void setGcount(int s);
	virtual string CompData();

};

int Ground::Groundcount = 0;

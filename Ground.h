#pragma once
#include "Components\Component.h"

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





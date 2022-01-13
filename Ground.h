#pragma once
#include "Components\Component.h"
#include <fstream>

class Ground :public Component
{
private:
	
public:

	static int Groundcount;

	int ground = -1;
	Ground(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual string CompData();
	virtual void Save(ofstream* file);
	//virtual void Save(fstream file);
	static int getGcount();
	static void setGcount(int s);
	Component* Copycomponent(GraphicsInfo* ginfo);
};





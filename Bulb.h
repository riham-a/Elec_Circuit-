#pragma once
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Components\Component.h"
class Bulb :public Component
{
	int on_off;
public:
	Bulb(GraphicsInfo* b_GfxInfo);
	Bulb(GraphicsInfo* b_GfxInfo, int on_of);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

	virtual string CompData();
	virtual void Save(fstream file);

};
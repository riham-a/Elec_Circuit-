#pragma once
#include "Components\Component.h"
class Bulb :public Component
{
	int on_off;
public:
	Bulb(GraphicsInfo* b_GfxInfo);
	Bulb(GraphicsInfo* b_GfxInfo, int on_of);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	int getON_OFF()
	{
		return on_off;
	}
	void setON_OFF(int o_F)
	{
		on_off = o_F;
	}
	virtual string CompData();
	//virtual void Save(fstream file);
	//virtual string CompData();
	Component* Copycomponent(GraphicsInfo* ginfo);
	virtual void Save(ofstream* file);

};
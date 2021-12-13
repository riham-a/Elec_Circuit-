#pragma once
#include "C:\Users\rawia\Desktop\Elec Circuit Code Framework\Components\Component.h"

class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(fstream file);
};
#pragma once
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Components\Component.h"

class Buzzer :public Component
{
public:
	Buzzer(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

};
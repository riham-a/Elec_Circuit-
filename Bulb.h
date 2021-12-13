#pragma once
#include "Components/Component.h"

class Bulb :public Component
{
public:
	Bulb(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(fstream file);
};
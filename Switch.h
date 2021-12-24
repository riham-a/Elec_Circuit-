#pragma once
#include "Components\Component.h"

class Switch :public Component
{
	int on_off;

public:
	Switch(GraphicsInfo* b_GfxInfo);
	Switch(GraphicsInfo* s_GfxInfo, int on_of);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual string CompData();

	virtual void Save(fstream file);

};
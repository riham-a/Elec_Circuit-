#pragma once
#include "Components\Component.h"
class Battery :public Component
{
public:
	Battery(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

	virtual string CompData();
	//virtual void Save(fstream file);
	Component* Copycomponent(GraphicsInfo* ginfo);
	virtual void Save(ofstream* file);


};
#pragma once

#include "Components\Component.h"
#include <fstream>



class Battery :public Component
{
public:
	Battery(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor

	virtual string CompData();

	Component* Copycomponent(GraphicsInfo* ginfo);
	virtual void Save(ofstream* file);


};
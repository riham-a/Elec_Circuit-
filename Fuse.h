#pragma once
#include "Components\Component.h"

class Fuse :public Component
{
public:
	Fuse(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual string CompData();
	virtual void Save(ofstream* file);
	Component* Copycomponent(GraphicsInfo* ginfo);
};
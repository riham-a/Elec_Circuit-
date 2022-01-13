#pragma once
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Components\Component.h"
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Module.h"
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Components\Component.h"


class Module: public Component
{

public:
	Module(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(ofstream* file);
	virtual string CompData();
	virtual void Load();
	virtual Component* Copycomponent(GraphicsInfo* ginfo);
	virtual void Save(fstream file);
};


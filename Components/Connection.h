#pragma once
#include "../UI/UI.h"
#include "Component.h"
#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Components\Component.h"

class Component;	//forward class declaration

class Connection 
{
	string con_Label;
	//connection connects between two compoenets
	Component	*Cmpnt1, *Cmpnt2;
	GraphicsInfo *pGfxInfo;	//The parameters required to draw a connection
	bool Selected;

public:
	Connection(GraphicsInfo *r_GfxInfo, Component *cmp1=nullptr, Component *cmp2=nullptr);

	virtual void Draw(UI* );	//for connection to Draw itself
	GraphicsInfo* getC_pGfxInfo();
	void setConnName(string s);
	void setComp1(Component *comp1);
	void setComp2(Component *comp2);

//	void Savecon(ofstream *file);
	void Savecon(fstream*file);
	bool ifSelected();
	void setSelected(bool sel);
};

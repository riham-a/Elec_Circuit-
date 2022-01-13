#pragma once

//#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\Actions\Action.h"
//#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\UI\UI.h"

#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Actions\Action.h"
#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\UI\UI.h"

#include "ApplicationManager.h"
#include "Defs.H"

class ActionSelect : public Action
{
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	ApplicationManager* pApp;
public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};


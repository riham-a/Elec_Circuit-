#pragma once
#include "Action.h"
//#include "UI\UI.h"
#include "../ApplicationManager.h"
//#include "Defs.H"

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


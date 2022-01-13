#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "ActionAddConnection.h"

class ActionDelete :public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionDelete(ApplicationManager* pApp);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	virtual ~ActionDelete(void);

};


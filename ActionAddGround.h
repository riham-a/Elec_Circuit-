#pragma once



#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\Actions\Action.h"
#include "Ground.h"
#include "ApplicationManager.h"

class ActionAddGround : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddGround(ApplicationManager* pApp);
	virtual ~ActionAddGround(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

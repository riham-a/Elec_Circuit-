#pragma once
#include "Actions\Action.h"
#include "Module.h"

//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Module.h"

#include "ApplicationManager.h"

class ActionAddModule : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddModule(ApplicationManager* pApp);
	virtual ~ActionAddModule(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};



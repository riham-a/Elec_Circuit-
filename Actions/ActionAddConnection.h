#pragma once
#include "Action.h"
#include "../Components/Connection.h"
#include "../Components/Component.h"

//Class responsible for adding a new connection action

class ActionAddConnection : public Action
{
private:
	//Parameters for Line of connection
	int x1, y1, x2, y2;	//Two corners of the line
	Component* Comp1;
	Component* Comp2; // Two components connected to each other
public:
	ActionAddConnection(ApplicationManager* pApp);
	ActionAddConnection(ApplicationManager* pApp, Component* comp1, Component* comp2);
	virtual ~ActionAddConnection(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};



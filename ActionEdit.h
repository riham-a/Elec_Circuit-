#pragma once
#include "Actions/action.h"
#include "ApplicationManager.h"

class ActionEdit : public Action
{
private:
	int x, y; // will be the inputs from mouse click 
	ApplicationManager* pApp;
public:
	ActionEdit(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~ActionEdit(void);
};
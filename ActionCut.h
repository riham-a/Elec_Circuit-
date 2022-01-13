#pragma once
#include "Actions/action.h"
#include "ApplicationManager.h"

class ActionCut : public Action
{
private:
	int x, y, cx, cy, x2,y2;
	ApplicationManager* pApp;
public:
	ActionCut(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~ActionCut(void);
};

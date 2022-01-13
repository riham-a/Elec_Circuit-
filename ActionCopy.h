#pragma once
#include "Actions/action.h"
#include "ApplicationManager.h"

class ActionCopy : public Action
{
private:
	int x, y, cx,cy; 
	ApplicationManager* pApp;
public:
	ActionCopy(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~ActionCopy(void);
};

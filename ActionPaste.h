#pragma once
#include "Actions/action.h"
#include "ApplicationManager.h"

class ActionPaste : public Action
{
private:
	int cx, cy; // these will be the graphics info for the new place to components 
	ApplicationManager* pApp;
public:
	ActionPaste(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~ActionPaste(void);
};

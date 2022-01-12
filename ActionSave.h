#pragma once
#include "ApplicationManager.h"
#include "Actions/action.h"
#include <fstream>

class ActionSave : public Action
{
private :
	ApplicationManager* pApp;
public:
	ActionSave(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo(); 
	virtual void Redo();
	virtual ~ActionSave(void);
};
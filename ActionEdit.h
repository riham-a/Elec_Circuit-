#pragma once
#include "Actions/action.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ApplicationManager.h"

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
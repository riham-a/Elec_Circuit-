#pragma once
#include "Actions/action.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"

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
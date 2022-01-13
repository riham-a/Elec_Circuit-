#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include <iostream>
using namespace std;
class VoltmeterAcion :public Action
{
private:
	ApplicationManager* pApp;
	Component* Cptr;
	double volt;
public:
	VoltmeterAcion(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~VoltmeterAcion(void);
};

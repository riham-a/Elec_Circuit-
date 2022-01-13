#pragma once
#include "Actions/Action.h"
#include "ApplicationManager.h"

//#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"

//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\ApplicationManager.h"

#include <fstream>
class ActionLoad : public Action
{
private:
	ApplicationManager* pApp;
public:
	ActionLoad(ApplicationManager* pApp);
	virtual void Execute();
	void Showcontent(fstream &file);
	virtual void Undo();
	virtual void Redo();

};
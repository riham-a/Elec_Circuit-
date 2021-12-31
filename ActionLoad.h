#pragma once
#include "Actions/Action.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ApplicationManager.h"
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
#pragma once
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\Actions\Action.h"
#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\ApplicationManager.h"
#include <iostream>
using namespace std;
class VoltmeterAcion :public Action
{
	double volt;
public:
	VoltmeterAcion(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual ~VoltmeterAcion(void);
};

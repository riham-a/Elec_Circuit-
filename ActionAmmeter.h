#pragma once
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ApplicationManager.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Actions\Action.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Components\Component.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;


class ActionAmmeter: public Action
{
private:
	ApplicationManager* pApp;
	Component* Cptr;
public:
	ActionAmmeter(ApplicationManager* pApp);
	void Execute();
	void Undo();
	void Redo();
	~ActionAmmeter(void);
};


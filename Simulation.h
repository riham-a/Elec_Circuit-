#pragma once

#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\ApplicationManager.h"
#include "Actions/action.h"


class Simulation : public Action
	{
	private:
		ApplicationManager* pApp;
	public:
		Simulation(ApplicationManager* pApp);
		virtual void Execute();
		virtual void Undo();
		virtual void Redo();
		virtual ~Simulation(void);
	
};


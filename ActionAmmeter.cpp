#include "ActionAmmeter.h"
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

ActionAmmeter::ActionAmmeter(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionAmmeter::Execute()
{

	int v = 0;
	int rtotal = 0;

	if (SIMULATION)
	{
		for (int i = 0; i < pManager->getCompCount(); i++)
		{
			if (pManager->getCompList()[i]->Getcomptype() == "Battery")
			{
				v = v + pManager->getCompList()[i]->GetValue();
			}
			else
			{
				rtotal = rtotal + pManager->getCompList()[i]->GetValue();
			}

		}

		Cptr->setcurrent(v / rtotal);
	}
	else
	{
		Cptr->setcurrent(0);
	}
	pManager->GetUI()->PrintMsg(to_string(Cptr->Getcurrent()));

}

void ActionAmmeter::Redo()
{

}
void ActionAmmeter::Undo()
{

}

ActionAmmeter::~ActionAmmeter()
{

}
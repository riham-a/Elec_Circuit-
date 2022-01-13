#include "Simulation.h"

Simulation::Simulation(ApplicationManager* pApp) : Action(pApp)
{
}

void Simulation::Execute()
{
	//UI* pUI = pManager->GetUI();
	//pUI->CreateSimulationToolBar();
	//int comp_connected = 0;
	////ApplicationManager* aptr;
	int comp_connected=0;

	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		if (((pManager->getCompList()[i]->gettermn1() + pManager->getCompList()[i]->gettermn1()) > 1) || (((pManager->getCompList()[i]->gettermn1() + pManager->getCompList()[i]->gettermn1()) == 1) && (pManager->getCompList()[i]->Getcomptype() == "Battery")))
		{
			comp_connected++;
		}
	}
	if (comp_connected == pManager->getCompCount())
	{
		UI* pUI = pManager->GetUI();
		pUI->CreateSimulationToolBar();
		pManager->GetUserAction();
		ActionType ActType;
		do
		{
			//Read user action
			ActType = pManager->GetUserAction();

			//Exexute the action
			pManager->ExecuteAction(ActType);

			//Update the drawing window
			pManager->UpdateInterface();


		} while (ActType != EXIT);
	}
	else
	{

		pManager->GetUI()->PrintMsg("circuit is not closed");
	}
}

void Simulation::Undo()
{
}

void Simulation::Redo()
{
}

Simulation::~Simulation(void)
{
}

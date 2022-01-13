#include "Simulation.h"
#include "ApplicationManager.h"
#include "Components/Component.h"
#include "Simulation.h"
#include<iostream>
using namespace std;
Simulation::Simulation(ApplicationManager* pApp) : Action(pApp)
{
}

void Simulation::Execute()
{
	int comp_connected = 0;
	//ApplicationManager* aptr;
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
	}
	else
	{
		cout << "circuit is not closed";
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

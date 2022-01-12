#include "Simulation.h"
#include "ApplicationManager.h"
#include "Components/Component.h"

Simulation::Simulation(ApplicationManager* pApp) : Action(pApp)
{
}

void Simulation::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->CreateSimulationToolBar();
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

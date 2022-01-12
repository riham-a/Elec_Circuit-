#include "ActionDelete.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"
#include "ActionAddConnection.h"

#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{

}

ActionDelete::~ActionDelete(void)
{
}

void ActionDelete::Execute()
{
	pManager->GetUI()->PrintMsg("Selected Componenet is deleted!");
	int index;
	Component* C = pManager->GetSelected(index);
	if (C != NULL)
	{
		C->deleteComp_Conns();
		pManager->deleteComp(index);
	}
}

void ActionDelete::Undo()
{}

void ActionDelete::Redo()
{}



#include "D:\ZC\Year3\Fall 2021\C++\Copy f my work\Elec Circuit Code Framework\VoltmeterAcion.h"

VoltmeterAcion::VoltmeterAcion(ApplicationManager* pApp) :Action(pApp)
{
}

VoltmeterAcion::~VoltmeterAcion(void)
{
}

void VoltmeterAcion::Execute()
{
	int item;
	Component* C = pManager->GetSelected(item);
	volt = C->getTerm1_volt() - C->getTerm2_volt();
	string StringVolt = to_string(volt);
	pManager->GetUI()->PrintMsg(StringVolt);
}

void VoltmeterAcion::Undo()
{}

void VoltmeterAcion::Redo()
{}
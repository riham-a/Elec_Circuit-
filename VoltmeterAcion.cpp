
#include "VoltmeterAcion.h"

VoltmeterAcion::VoltmeterAcion(ApplicationManager* pApp) :Action(pApp)
{
}



void VoltmeterAcion::Execute()
{
	/*int item;
    Component* C = pManager->GetSelected(item);
	volt = C->getTerm1_volt() - C->getTerm2_volt();
	string StringVolt = to_string(volt);
	pManager->GetUI()->PrintMsg(StringVolt);*/
////////////////////////////////////////////////////////////////////////////////


	double v = 0;
	double rtotal = 0;



	for (int i = 0; i < pManager->getCompCount(); i++)
	{
		cout << "riham m3toha" << endl;
		if (pManager->getCompList()[i]->CompData() == "Battery")
		{
			v = v + pManager->getCompList()[i]->GetValue();
		}
		else
		{
			rtotal = rtotal + pManager->getCompList()[i]->GetValue();
		}

	}
	double c = 0;
	c = v / rtotal;
	int index;
	Cptr = pManager->GetSelected(index);
	if (Cptr == nullptr)
	{
		cout << "Riham equal null" << endl;
	}
	else
	{
		cout << "Riham equal finaline" << endl;
		cout << c << endl;
		Cptr->setcurrent(c);
		pManager->GetUI()->PrintMsg(to_string(Cptr->GetValue()*c));

	}

////////////////////////////////////////////////////////////////////////////
}

VoltmeterAcion::~VoltmeterAcion(void)
{
}

void VoltmeterAcion::Undo()
{}

void VoltmeterAcion::Redo()
{}
#include "ActionAmmeter.h"


ActionAmmeter::ActionAmmeter(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionAmmeter::Execute()
{

	double v = 0;
	double rtotal = 0;



		for (int i = 0; i < pManager->getCompCount(); i++)
		{
			cout << "riham m3toha"<<endl;
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
			cout << c<<endl;
			Cptr->setcurrent(c);
			pManager->GetUI()->PrintMsg(to_string(Cptr->Getcurrent()));

		}
		


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
#include "ActionAddConnection.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\ApplicationManager.h"


ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
{

}
ActionAddConnection::ActionAddConnection(ApplicationManager* pApp, Component* comp1, Component* comp2) :Action(pApp)
{
	Comp1 = comp1;
	Comp2 = comp2;
}

ActionAddConnection::~ActionAddConnection(void)
{
}

void ActionAddConnection::Execute()
{
		//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
		//Print Action Message
	pUI->PrintMsg("Adding a new connection: Click at the terminal of the First Component");
	pUI->GetPointClicked(x1, y1);
	pUI->ClearStatusBar();
	Component* C1 = pManager->Findcomp(x1, y1);
	Point* P1 = new Point();
	P1->x = x1; P1->y = y1;
	Point* P2 = new Point();
	P2->x = x2; P2->y = y2;
	if (C1 == NULL)
	{
		pUI->PrintMsg("Please, Click at a valid component");
		pUI->GetPointClicked(x1, y1);
	}
	else
	{
		if (C1->returnTerr1(P1))
		{
			Comp1 = C1;
			pUI->PrintMsg("Click at the terminal of the Second Component");
			pUI->GetPointClicked(x2, y2);
		}
		else if (C1->returnTerr2(P1))
		{
			Comp2 = C1;
			pUI->PrintMsg("Click at the terminal of the Second Component");
			pUI->GetPointClicked(x2, y2);
		}
		else
		{
			pUI->PrintMsg("This Component exceeds its maximum number of connections");
		}
	}

	Component* C2 = pManager->Findcomp(x2, y2);
	if (C2 != nullptr)
	{
		/*if (C2->returnTerr1(P2))
		{
			Comp1 = C2;
		}
		else if (C2->returnTerr2(P2))
		{
			Comp2 = C2;
		}
		else
		{
			pUI->PrintMsg("This Component exceeds its maximum number of connections");
		}*/
		if (C1 == Comp1) Comp2 = C2;
		if (C2 == Comp1) Comp2 = C1;

	}
	else
	{
		pUI->PrintMsg("Please, Click at a valid component");
	}
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;
	if ((Comp1 && Comp2) && (Comp1 != Comp2))
	{

		if (((Comp1->gettermn1() + Comp1->gettermn2()) < 2) || (((Comp1->gettermn1() + Comp1->gettermn2()) < 3) && (Comp1->Getcomptype() == "Ground") && ((Comp2->gettermn1() + Comp2->gettermn2()) < 2) || (((Comp2->gettermn1() + Comp2->gettermn2()) < 3) && (Comp2->Getcomptype() == "Ground"))))

		{
			Connection* pC = new Connection(pGInfo, Comp1, Comp2);
			pManager->AddConnection(pC, Comp1, Comp2);   /// Adding new connection
			Comp1->AddtoConnectionsTerm1(pC);
			Comp2->AddtoConnectionsTerm2(pC);
			pUI->ClearStatusBar();
			pUI->PrintMsg("Connection done successfully!");
		}
		else
		{
			pUI->PrintMsg("Parallel circuit is not allowed");
		}

	}
}

void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}



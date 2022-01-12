#include "ActionAddConnection.h"

#include "../ApplicationManager.h"

ActionAddConnection::ActionAddConnection(ApplicationManager* pApp/*, Component* comp1, Component* comp2*/) :Action(pApp)
{
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

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked( x1, y1);

	//Clear Status Bar
	pUI->ClearStatusBar();

	//Print Action Message
	pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(x2, y2);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection

	pGInfo->PointsList[0].x = x1;
	pGInfo->PointsList[0].y = y1;
	pGInfo->PointsList[1].x = x2;
	pGInfo->PointsList[1].y = y2;

	Connection* pC = new Connection(pGInfo, Comp1, Comp2);
	pManager->AddConnection(pC, Comp1, Comp2);   /// Adding new connection
	pUI->PrintMsg("Enter the name of this connection");
	string m_label = pUI->GetSrting();
	pC->setConnName(m_label);
	pUI->ClearStatusBar();

}

void ActionAddConnection::Undo()
{}

void ActionAddConnection::Redo()
{}



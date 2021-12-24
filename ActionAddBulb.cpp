#include "ActionAddBulb.h"

ActionAddBulb::ActionAddBulb(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBulb::~ActionAddBulb(void)
{
}

void ActionAddBulb::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Bulb: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	pUI->PrintMsg("Enter the name of Bulb");
	string m_label = pUI->GetSrting();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter value: ");
	string v_label = pUI->GetSrting();
	int value = stoi(v_label);
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter 0 for OFF, or 1 for ON: ");
	string ON_OFF = pUI->GetSrting();
	int ON_OF = stoi(ON_OFF);
	pUI->ClearStatusBar();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Bulb* pB = new Bulb(pGInfo, ON_OF);
	pManager->AddComponent(pB);
}

void ActionAddBulb::Undo()
{}

void ActionAddBulb::Redo()
{}
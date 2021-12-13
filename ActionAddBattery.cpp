#include "ActionAddBattery.h"



ActionAddBattery::ActionAddBattery(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBattery::~ActionAddBattery(void)
{
}

void ActionAddBattery::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Battery: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Battery* pBat = new Battery(pGInfo);
	pManager->AddComponent(pBat);

	pUI->PrintMsg("Enter the name of Battery : ");
	string m_label = pUI->GetSrting();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter a value : ");
	string v_label = pUI->GetSrting();
	int value = stoi(v_label);
	pUI->ClearStatusBar();
}

void ActionAddBattery::Undo()
{}

void ActionAddBattery::Redo()
{}
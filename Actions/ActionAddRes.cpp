#include "ActionAddRes.h"

ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{
	
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();	
		
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	
	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth/2;
	pGInfo->PointsList[0].y = Cy - compHeight/2;
	pGInfo->PointsList[1].x = Cx + compWidth/2;
	pGInfo->PointsList[1].y = Cy + compHeight/2;
	pUI->PrintMsg("Enter the name of resistor");
	string m_label = pUI->GetSrting();
	pUI->ClearStatusBar();
	pUI->PrintMsg("Enter the value of resistance");
	string v_label = pUI->GetSrting();
	double value = stod(v_label);
	pUI->ClearStatusBar();
	Resistor* pR = new Resistor(pGInfo);
	pR->setCompName(m_label);
	pR->setCompValue(value);
	pManager->AddComponent(pR);
}

void ActionAddRes::Undo()
{}

void ActionAddRes::Redo()
{}


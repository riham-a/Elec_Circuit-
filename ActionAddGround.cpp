#include "ActionAddGround.h"

ActionAddGround::ActionAddGround(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddGround::~ActionAddGround(void)
{
}

void ActionAddGround::Execute()
{
   
	   //Get a Pointer to the user Interfaces
	   UI* pUI = pManager->GetUI();
	   GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	   Ground* pG = new Ground(pGInfo);
	   string m_label = pUI->GetSrting();

	   if ( pG->Groundcount < 1)
	   {
	   //Print Action Message
	   pUI->PrintMsg("Adding a new Ground: Click anywhere to add");

	   //Get Center point of the area where the Comp should be drawn
	   pUI->GetPointClicked(Cx, Cy);

	   //Clear Status Bar
	   pUI->ClearStatusBar();
	   pUI->PrintMsg("Enter the name of Ground");
	   pUI->ClearStatusBar();

   //Calculate the rectangle Corners
	   int compWidth = pUI->getCompWidth();
	   int compHeight = pUI->getCompHeight();
	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	   pGInfo->PointsList[0].x = Cx - compWidth / 2;
	   pGInfo->PointsList[0].y = Cy - compHeight / 2;
	   pGInfo->PointsList[1].x = Cx + compWidth / 2;
	   pGInfo->PointsList[1].y = Cy + compHeight / 2;

	//pUI->PrintMsg("Enter the name of Ground");
	//pUI->ClearStatusBar();
	Ground* pG = new Ground(pGInfo);
	   pManager->AddComponent(pG);
	   pG->Groundcount++;
       }
   else
   {
	   pUI->PrintMsg("You can't add more than one ground");
   }
	pG->setCompName(m_label);
	pG->setCompValue(-1.0);
	pManager->AddComponent(pG);
}

void ActionAddGround::Undo()
{}

void ActionAddGround::Redo()
{}
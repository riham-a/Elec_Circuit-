#include "ActionSelect.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{

}
 void ActionSelect::Execute()
{

	 //Get a Pointer to the user Interfaces
	 UI* pUI = pManager->GetUI();
	 int Counter = 0;
	 for (int i = 0; i < pManager->getCompCount(); i++)
	 {
		 
		 Component* C = pManager->getCompList()[i];
		 int X1 = C->getM_pGfxInfo()->PointsList[0].x;
		 int Y1 = C->getM_pGfxInfo()->PointsList[0].y;
		 int X2 = X1 + pUI->getCompWidth();
		 int Y2 = Y1 + pUI->getCompHeight();
		 int MouseX, MouseY;
		 pUI->GetPointClicked(MouseX, MouseY);
		 if (((MouseX >= X1) && (MouseX <= X2)) && ((MouseY >= Y1) && (MouseY <= Y2)))
		 {
			 C->setSelected(true);
			 C->Draw(pUI);
			 pUI->PrintMsg("you have selected hn");
		 }
		 else
		 {
			 Counter++;
		 }
		 
	 }
	 if (Counter == pManager->getCompCount())
	 {
		 for (int i = 0; i < pManager->getCompCount(); i++)
		 {

			 Component* C = pManager->getCompList()[i];
			 
				 C->setSelected(false);
				 C->Draw(pUI);
				 pUI->ClearStatusBar();
		 }
	 }
 
	 /*
	 //Print Action Message
	 pUI->PrintMsg("Adding a new Fuse: Click anywhere to add");

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

	 Fuse* pF = new Fuse(pGInfo);
	 pManager->AddComponent(pF);
	 */
}
 ActionSelect::~ActionSelect(void)
 {
 }
 void ActionSelect::Undo()
 {}

 void ActionSelect::Redo()
 {}

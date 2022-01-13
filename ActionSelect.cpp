#include "ActionSelect.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{

}
 void ActionSelect::Execute()
{

	 //Get a Pointer to the user Interfaces
	 UI* pUI = pManager->GetUI();
	 int Counter = 0;
	 int X1, Y1, X2, Y2, MouseX, MouseY;
	 pUI->GetPointClicked(MouseX, MouseY);
	 Connection* pC = pManager->Findconnection(MouseX, MouseY);
	 for (int i = 0; i < pManager->getCompCount(); i++)   //Select -> Riham
	 {
		 
		 Component* C = pManager->getCompList()[i];
		  X1 = C->getM_pGfxInfo()->PointsList[0].x;
		  Y1 = C->getM_pGfxInfo()->PointsList[0].y;
		  X2 = X1 + pUI->getCompWidth();
		  Y2 = Y1 + pUI->getCompHeight();
		 if (((MouseX >= X1) && (MouseX <= X2)) && ((MouseY >= Y1) && (MouseY <= Y2)))
		 {
			 C->setSelected(true);
			 C->Draw(pUI);
			 pUI->PrintMsg(C->CompData());
			 window* pWind = pUI->getPWind();
			 pWind->SetPen(RED);
			 pWind->DrawString(X1, Y1-20, C->GetName());
			 std::string s = std::to_string(C->GetValue());
			 pWind->DrawString(X1, Y1 - 40, s);
		/*	 std::string I= std::to_string(C->Getcurrent());
			 pWind->DrawString(X1, Y1 - 40, I);
			 std::string v = std::to_string(C->Getvolt());
			 pWind->DrawString(X1, Y1 - 40, v);*/
		 }
		 else
		 {
			 Counter++;
		 }
		 
	 }
	 if (pUI->getPWind()->GetColor(MouseX, MouseY) == BLUE)
	 {
		 /*if (pC != NULL)
		 {
			 pC->setSelected(true);
			 pManager->UpdateInterface();
		 }*/
	 }
	 //if (pC == NULL)
	 {
		 if (Counter == pManager->getCompCount()) //Unselect -> Riham
		 {
			 window* pWind = pUI->getPWind();
			 for (int i = 0; i < pManager->getCompCount(); i++)
			 {

				 Component* C = pManager->getCompList()[i];

				 C->setSelected(false);
				 X1 = C->getM_pGfxInfo()->PointsList[0].x;
				 Y1 = C->getM_pGfxInfo()->PointsList[0].y;
				 X2 = X1 + pUI->getCompWidth();
				 Y2 = Y1 + pUI->getCompHeight();
				 pWind->SetPen(WHITE);
				 pWind->DrawRectangle(X1, Y1, X1 + 100, Y1 - 40);
				 pUI->ClearStatusBar();
			 }
			 pManager->UpdateInterface();

		 }
	 }
	 
}
 ActionSelect::~ActionSelect(void)
 {
 }
 void ActionSelect::Undo()
 {}

 void ActionSelect::Redo()
 {}

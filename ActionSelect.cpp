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
	 window* pWind;
	 GraphicsInfo* sw_GF = new GraphicsInfo(2);
	 for (int i = 0; i < pManager->getCompCount(); i++)   //Select -> Riham
	 {

		 Component* C = pManager->getCompList()[i];
		 X1 = C->getM_pGfxInfo()->PointsList[0].x;
		 Y1 = C->getM_pGfxInfo()->PointsList[0].y;
		 X2 = X1 + pUI->getCompWidth();
		 Y2 = Y1 + pUI->getCompHeight();
		 if (((MouseX >= X1) && (MouseX <= X2)) && ((MouseY >= Y1) && (MouseY <= Y2)))
		 {
			 if (C->CompData() != "Switch" && C->CompData() != "Bulb") // As they have other limitations
			 {
				 C->setSelected(true);
				 C->Draw(pUI);
				 pUI->PrintMsg(C->CompData());
				 pWind = pUI->getPWind();
				 pWind->SetPen(RED);
				 pWind->DrawString(X1, Y1 - 20, C->GetName());
				 std::string s = std::to_string(C->GetValue());
				 pWind->DrawString(X1, Y1 - 40, s);
			 }
			 else if (C->CompData() == "Switch")
			 {
				 pUI->ClearStatusBar();
				 pUI->PrintMsg("Enter S for Selection or CH for Change mode: ");
				 string Option = pUI->GetSrting();
				 if (Option == "S" || Option == "s")
				 {
					 C->setSelected(true);
					 C->Draw(pUI);
					 pUI->PrintMsg(C->CompData());
					 pWind = pUI->getPWind();
					 pWind->SetPen(RED);
					 pWind->DrawString(X1, Y1 - 20, C->GetName());
					 std::string s = std::to_string(C->GetValue());
					 pWind->DrawString(X1, Y1 - 40, s);
				 }
				 else if (Option == "CH" || Option == "ch")
				 {
					 sw_GF->PointsList[0].x = X1;
					 sw_GF->PointsList[1].x = X2;
					 sw_GF->PointsList[0].y = Y1;
					 sw_GF->PointsList[1].y = Y2;
					 Switch* sw = new Switch(sw_GF);
					 sw = dynamic_cast <Switch*> (C);
					 if (sw->getON_OFF() == 1)
					 {
						 sw->setON_OFF(0);
						 pUI->ClearStatusBar();
						 pUI->PrintMsg("Switch has been changed to Off mode!");
						 pManager->UpdateInterface();
					 }
					 else if (sw->getON_OFF() == 0)
					 {
						 sw->setON_OFF(1);
						 pUI->ClearStatusBar();
						 pUI->PrintMsg("Switch has been changed to On mode!");
						 pManager->UpdateInterface();
					 }
				 }
				 else
				 {
					 pUI->PrintMsg("Please, Enter only S oe CH");
				 }
			 }
			 else if (C->CompData() == "Bulb")
			 {
				 pUI->ClearStatusBar();
				 pUI->PrintMsg("Enter S for Selection or CH for Change mode: ");
				 string Option = pUI->GetSrting();
				 if (Option == "S")
				 {
					 C->setSelected(true);
					 C->Draw(pUI);
					 pUI->PrintMsg(C->CompData());
					 pWind = pUI->getPWind();
					 pWind->SetPen(RED);
					 pWind->DrawString(X1, Y1 - 20, C->GetName());
					 std::string s = std::to_string(C->GetValue());
					 pWind->DrawString(X1, Y1 - 40, s);
				 }
				 else if (Option == "CH")
				 {
					 sw_GF->PointsList[0].x = X1;
					 sw_GF->PointsList[1].x = X2;
					 sw_GF->PointsList[0].y = Y1;
					 sw_GF->PointsList[1].y = Y2;
					 Bulb* b = new Bulb(sw_GF);
					 b = dynamic_cast <Bulb*> (C);
					 if (b->getON_OFF() == 1)
					 {
						 b->setON_OFF(0);
						 pUI->ClearStatusBar();
						 pUI->PrintMsg("Bulb has been changed to Off mode!");
						 pManager->UpdateInterface();
					 }
					 else if (b->getON_OFF() == 0)
					 {
						 b->setON_OFF(1);
						 pUI->ClearStatusBar();
						 pUI->PrintMsg("Bulb has been changed to On mode!");
						 pManager->UpdateInterface();
					 }
				 }
				 else
				 {
					 pUI->PrintMsg("Please, Enter only S oe CH");
				 }
			 }
		 }
			 else
			 {
				 Counter++;
			 }
			 if (pUI->getPWind()->GetColor(MouseX, MouseY) == BLUE)
			 {
				 /*if (pC != NULL)
				 {
					 pC->setSelected(true);
					 pManager->UpdateInterface();
				 }*/
			 }
		 
	 }
	 //if (pC == NULL)
	 //{
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
	// }
	 
}
 ActionSelect::~ActionSelect(void)
 {
 }
 void ActionSelect::Undo()
 {}

 void ActionSelect::Redo()
 {}

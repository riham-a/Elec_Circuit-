#include "ActionEdit.h"

//#include "UI/UI.h"
//#include "Components/Component.h"
//#include "Components/Connection.h"

ActionEdit::ActionEdit(ApplicationManager* pApp) : Action (pApp)
{
}

void ActionEdit::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Editing: click on component or connection to edit");
	pUI->GetPointClicked(x, y);
	Component* Compn = pManager->Findcomp(x, y);
	Connection* conn = pManager->Findconnection(x, y);

	if (Compn != nullptr)
	{
		pUI->PrintMsg("Print 1 to change the name and 2 for change the value ");
		string choice = pUI->GetSrting();
		if (choice == "1")
		{
			pUI->PrintMsg("Enter the new name for component: ");
			string newname = pUI->GetSrting();
			pUI->ClearStatusBar();
			Compn->setCompName(newname);
			pUI->PrintMsg("You have changed the name successfully ");
			//Block(30)
			pUI->ClearStatusBar();
		}
		else
		{
			pUI->PrintMsg("Enter the new value for component: ");
			string newvalue = pUI->GetSrting();
			pUI->ClearStatusBar();
			Compn->setCompValue(stod(newvalue));

		}
	}

	else if ((conn != nullptr))
	{
		pUI->PrintMsg("Print 1 to change the name and 2 for change one of connected components ");
		string choice = pUI->GetSrting();
		if (choice == "1")
		{
			pUI->PrintMsg("Enter the new name for component: ");
			string newname = pUI->GetSrting();
			pUI->ClearStatusBar();
			Compn->setCompName(newname);
			pUI->PrintMsg("You have changed the name successfully ");
			//Block(30);
			pUI->ClearStatusBar();
		}
		else
		{
			pUI->PrintMsg("Click on the terminal you want to delete:  ");
			pUI->GetPointClicked(x, y);
			pUI->ClearStatusBar();
			Component* Compx = pManager->Findcomp(x, y);
			pUI->PrintMsg("Click on the terminal you want to add instead:  ");
			pUI->GetPointClicked(x, y);
			pUI->ClearStatusBar();
			Component* Comp1 = pManager->Findcomp(x, y);
			conn->setComp1(Comp1);
			pUI->PrintMsg("Do you want to change the other terminal ? y/n ");
			string yn = pUI->GetSrting();
			if (yn == "y")
			{
				pUI->PrintMsg("Click on the terminal you want to delete:  ");
				pUI->GetPointClicked(x, y);
				pUI->ClearStatusBar();
				Component* Compnx = pManager->Findcomp(x, y);
				pUI->PrintMsg("Click on the terminal you want to add instead:  ");
				pUI->GetPointClicked(x, y);
				pUI->ClearStatusBar();
				Component* Compn1 = pManager->Findcomp(x, y);
				conn->setComp1(Compn1);
			}
			else
			{
				pUI->ClearStatusBar();
			}
		}
	}
}

ActionEdit::~ActionEdit(void)
{
}
void ActionEdit::Undo()
{
}

void ActionEdit::Redo()
{
}
//#include "ActionEdit.h"
//#include "ApplicationManager.h"
////#include "UI/UI.h"
////#include "Components/Component.h"
////#include "Components/Connection.h"
//
//ActionEdit::ActionEdit(ApplicationManager* pApp) : Action (pApp)
//{
//}
//
//void ActionEdit::Execute()
//{
//	UI* pUI = pManager->GetUI();
//	pUI->PrintMsg("Editing: click on component or connection to edit");
//	pUI->GetPointClicked(x, y);
//	Component* Compn = pManager->Findcomp(x, y);
//	Connection* conn = pManager->Findconnection(x, y);
//
//	if (Compn != nullptr)
//	{
//		pUI->PrintMsg("Print 1 to change the name and 2 for change the value ");
//		string choice = pUI->GetSrting();
//		if (choice == "1")
//		{
//			pUI->PrintMsg("Enter the new name for component: ");
//			string newname = pUI->GetSrting();
//			pUI->ClearStatusBar();
//			Compn->setCompName(newname);
//			pUI->PrintMsg("You have changed the name successfully ");
//			//Block(30)
//			pUI->ClearStatusBar();
//		}
//		else
//		{
//			pUI->PrintMsg("Enter the new value for component: ");
//			string newvalue = pUI->GetSrting();
//			pUI->ClearStatusBar();
//			Compn->setCompValue(stod(newvalue));
//
//		}
//	}
//
//	else if ((conn != nullptr))
//	{
//		pUI->PrintMsg("Print 1 to change the name and 2 for change one of connected components ");
//		string choice = pUI->GetSrting();
//		if (choice == "1")
//		{
//			pUI->PrintMsg("Enter the new name for component: ");
//			string newname = pUI->GetSrting();
//			pUI->ClearStatusBar();
//			Compn->setCompName(newname);
//			pUI->PrintMsg("You have changed the name successfully ");
//			//Block(30);
//			pUI->ClearStatusBar();
//		}
//		else
//		{
//			pUI->PrintMsg("Click on the terminal you want to delete:  ");
//			pUI->GetPointClicked(x, y);
//			pUI->ClearStatusBar();
//			Component* Compx = pManager->Findcomp(x, y);
//			pUI->PrintMsg("Click on the terminal you want to add instead:  ");
//			pUI->GetPointClicked(x, y);
//			pUI->ClearStatusBar();
//			Component* Comp1 = pManager->Findcomp(x, y);
//			conn->setComp1(Comp1);
//			pUI->PrintMsg("Do you want to change the other terminal ? y/n ");
//			string yn = pUI->GetSrting();
//			if (yn == "y")
//			{
//				pUI->PrintMsg("Click on the terminal you want to delete:  ");
//				pUI->GetPointClicked(x, y);
//				pUI->ClearStatusBar();
//				Component* Compnx = pManager->Findcomp(x, y);
//				pUI->PrintMsg("Click on the terminal you want to add instead:  ");
//				pUI->GetPointClicked(x, y);
//				pUI->ClearStatusBar();
//				Component* Compn1 = pManager->Findcomp(x, y);
//				conn->setComp1(Compn1);
//			}
//			else
//			{
//				pUI->ClearStatusBar();
//			}
//		}
//	}
//}
//
//ActionEdit::~ActionEdit(void)
//{
//}
//void ActionEdit::Undo()
//{
//}
//
//void ActionEdit::Redo()
//{
//}


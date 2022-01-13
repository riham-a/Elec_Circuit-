#include "ActionCopy.h"
ActionCopy::ActionCopy(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionCopy::Execute()
{
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Copying a component: Click on the component you want to copy");
	pUI->GetPointClicked(x, y);
	Component* Compn = pManager->Findcomp(x, y);
	if (Compn != nullptr)
	{
		pUI->PrintMsg("Pasting a component: Click ");
		pUI->GetPointClicked(cx, cy);
		GraphicsInfo* pGInfo = new GraphicsInfo(2);
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();
		pGInfo->PointsList[0].x = cx - compWidth / 2;
		pGInfo->PointsList[0].y = cy - compHeight / 2;
		pGInfo->PointsList[1].x = cx + compWidth / 2;
		pGInfo->PointsList[1].y = cy + compHeight / 2;
		pUI->PrintMsg("Enter the name ");
		string m_label = pUI->GetSrting();
		pUI->ClearStatusBar();
		pUI->PrintMsg("Enter a value: ");
		string v_label = pUI->GetSrting();
		double value = stod(v_label);
		pUI->ClearStatusBar();
		Compn->setCompName(m_label); Compn->setCompValue(value);
		Compn = pManager->forCopy(Compn, pGInfo);
		pManager->AddComponent(Compn);
	}
	else
	{
		pUI->ClearStatusBar();
		pUI->PrintMsg("no component here");
	}
		
}

void ActionCopy::Undo()
{
}

void ActionCopy::Redo()
{
}

ActionCopy::~ActionCopy(void)
{
}

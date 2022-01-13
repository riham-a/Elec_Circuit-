#include "ActionCut.h"

ActionCut::ActionCut(ApplicationManager* pApp) :Action(pApp)
{
}

void ActionCut::Execute()
{
	UI* pUI = pManager->GetUI();
	window* pWind = pUI->getPWind();
	pUI->PrintMsg("Cutting a component: Click on the component you want to cut");
	pUI->GetPointClicked(x, y);
	Component* Compn = pManager->Findcomp(x, y);
	if (Compn != nullptr)
	{
		Compn->deleteComp_Conns();
		x = Compn->getM_pGfxInfo()->PointsList[0].x;
		y = Compn->getM_pGfxInfo()->PointsList[0].y;
		x2 = x + pUI->getCompWidth();
		y2 = y + pUI->getCompHeight();
		pWind->SetPen(WHITE);
		pWind->DrawRectangle(x, y, x2,y2);
		pUI->ClearStatusBar();
		pUI->PrintMsg("Pasting a component: Click to paste the component");
		pUI->GetPointClicked(cx, cy);
		pManager->changeGraphicInfo(cx, cy, Compn->getM_pGfxInfo());
	}
	else 
		pUI->PrintMsg("no component here");
}

void ActionCut::Undo()
{
}

void ActionCut::Redo()
{
}

ActionCut::~ActionCut(void)
{
}

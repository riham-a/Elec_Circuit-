#include "ApplicationManager.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}

Component* ApplicationManager::Findcomp(int x, int y)
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)
	{
		Component* C = CompList[i];
		int X1 = C->getM_pGfxInfo()->PointsList[0].x;
		int Y1 = C->getM_pGfxInfo()->PointsList[0].y;
		int X2 = X1 + pUI->getCompWidth();
		int Y2 = Y1 + pUI->getCompHeight();
		if (((x >= X1) && (x <= X2)) && ((y >= Y1) && (y <= Y2)))
		{
			return C;
		}
		else
			c++;
	}
	if (c == CompCount)
		return nullptr;
}



//Connection* ApplicationManager::Findconnection(int x, int y)
//{
//	int C = 0;
//	for (int i = 0; i < ConnCount; i++)
//	{
//		Connection* C = Connlist[i];
//		int X1 = C->getC_pGfxInfo()->PointsList[0].x;
//		int Y1 = C->getC_pGfxInfo()->PointsList[0].y;
//		int X2 = C->getC_pGfxInfo()->PointsList[1].x;
//		int Y2 = C->getC_pGfxInfo()->PointsList[1].y;
//		double x1 = static_cast <double> (X1); 
//		double y1 = static_cast <double> (Y1);
//		double x2 = static_cast <double> (X2);
//		double y2 = static_cast <double> (Y2);
//		double slope; double b; // b is the part from y axis
//		slope = (y2 - y1) / (x2 - x1);
//		b = abs( Y2 - (slope * X2));
//		if ((y / x) == slope && (b = abs(x - (slope * x))))
//		//if(((X1 == x)||(X2 == x))&& ((Y1 == y)||(Y2 == y) ))
//		{
//			return C;
//		}
//	}
//	if (C == ConnCount)
//	{
//		return nullptr;
//	}
//}

void ApplicationManager::savef(ofstream *file)
{
	/**file << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		CompCount;
		CompList[i]->Save(file);
	}
	*file << ConnCount << endl;
	for (int i = 0; i < ConnCount; i++)
	{
		ConnCount;
		Connlist[i]->Savecon(file);
	}*/
}
Component* ApplicationManager::forCopy(Component * pcopied, GraphicsInfo* gInfo)
{
	return pcopied->Copycomponent(gInfo);
}

GraphicsInfo * ApplicationManager::changeGraphicInfo(int cx, int cy,GraphicsInfo* pGInfo)
{
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();
	pGInfo->PointsList[0].x = cx - compWidth / 2;
	pGInfo->PointsList[0].y = cy - compHeight / 2;
	pGInfo->PointsList[1].x = cx + compWidth / 2;
	pGInfo->PointsList[1].y = cy + compHeight / 2;
	return pGInfo;
}




////////////////////////////////////////////////////////////////////
// //By Riham
////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////
// //By Riham
 void ApplicationManager::AddConnection(Connection* pCon, Component* Comp1, Component* Comp2)
{
	/*if(! Comp1->AddtoConnectionsTerm1(pCon))
		pUI->PrintMsg("The first component execeeds its max of connections");
	 if (!Comp2->AddtoConnectionsTerm2(pCon))
		 pUI->PrintMsg("The second component execeeds its max of connections");*/
	 //pUI->DrawConnection(*pCon->getC_pGfxInfo());
	 Connlist[ConnCount++] = pCon;
}
////////////////////////////////////////////////////////////////////
int ApplicationManager::getCompCount()
{
	return CompCount;
}
////////////////////////////////////////////////////////////////////
// //By Riham
////////////////////////////////////////////////////////////////////
Component** ApplicationManager::getCompList()
{
	return CompList;
}
////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		case ADD_Bulb:
			pAct = new ActionAddBulb(this);
			break;
		case ADD_Switch:
			pAct = new ActionAddSwitch(this);
			break;
		case ADD_Battery:
			pAct = new ActionAddBattery(this);
			break;
		case ADD_Ground:
			pAct = new ActionAddGround(this);
			break;
		case ADD_Buzzer:
			pAct = new ActionAddBuzzer(this);
			break;
		case ADD_Fuse:
			pAct = new ActionAddFuse(this);
			break;
		case ADD_CONNECTION:
			pAct = new ActionAddConnection(this);
			break;

		case ADD_Module:
			pAct = new ActionAddModule(this);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		/*case EDIT_Label:
			pAct = new ActionEdit(this);
			break;*/
		case SAVE: 
			pAct = new ActionSave(this);
			break;
		case SIM_MODE:
			pAct = new Simulation(this);
			break;
		case LOAD: 
			pAct = new ActionLoad(this);
			break;
		case DEL:
			pAct = new ActionDelete(this);
		case COPY:
			pAct = new ActionCopy(this);
			break;
		case PASTE:
			pAct = new ActionPaste(this);
			break;
		case CUT:
			pAct = new ActionCut(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////
		
void ApplicationManager::UpdateInterface()
{
	Bulb_to_Switch();
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i])
			CompList[i]->Draw(pUI);
	}
	for (int i = 0; i < ConnCount; i++)
	{
		if (Connlist[i])
			Connlist[i]->Draw(pUI);
	}
}
Component* ApplicationManager::GetSelected(int& index)
{
	Component* SelectedCom = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IFSelected())
		{
			SelectedCom = CompList[i];
			index = i;
		}
	}
	return SelectedCom;
}
void ApplicationManager::deleteComp(int index)
{
	//Component* newComplist[MaxCompCount];
	for (int i = index; i < CompCount; i++)
	{
		if(i != CompCount-1)
		CompList[i] = CompList[i + 1];
	}
	CompCount--;
	pUI->ClearDrawingArea();
	UpdateInterface();
}
////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
///////////////////////////////Riham////////////////////////////////////////
void ApplicationManager::Bulb_to_Switch()
{
	GraphicsInfo* gf = new GraphicsInfo(2);
	Component* C;
	Switch* sw = NULL;
	Bulb* b = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		C = CompList[i];
		
		if (C->CompData() == "Bulb")
			b = dynamic_cast <Bulb*> (C);
		if (C->CompData() == "Switch")
			sw = dynamic_cast <Switch*> (C);
	}
	if (sw && b)
	{
		if (sw->getON_OFF())
			b->setON_OFF(true);
		else
			b->setON_OFF(false);
	}
}
////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
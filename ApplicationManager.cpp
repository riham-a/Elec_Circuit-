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
		return NULL;
}

Connection* ApplicationManager::Findconnection(int x, int y)
{
	int C = 0;
	for (int i = 0; i < ConnCount; i++)
	{
		Connection* C = Connlist[i];
		int X1 = C->getC_pGfxInfo()->PointsList[0].x;
		int Y1 = C->getC_pGfxInfo()->PointsList[0].y;
		int X2 = C->getC_pGfxInfo()->PointsList[1].x;
		int Y2 = C->getC_pGfxInfo()->PointsList[1].y;
		double x1 = static_cast <double> (X1); 
		double y1 = static_cast <double> (Y1);
		double x2 = static_cast <double> (X2);
		double y2 = static_cast <double> (Y2);
		double slope; double b; // b is the part from y axis
		slope = (y2 - y1) / (x2 - x1);
		b = abs( Y2 - (slope * X2));
		if ((y / x) == slope && (b = abs(x - (slope * x))))
		//if(((X1 == x)||(X2 == x))&& ((Y1 == y)||(Y2 == y) ))
		{
			return C;
		}
	}
	if (C == ConnCount)
	{
		return NULL;
	}
}

void ApplicationManager::savef(fstream *file)
{
	for (int i = 0; i < CompCount; i++)
	{
		CompCount;
		CompList[i]->Save(file);
	}
	for (int i = 0; i < ConnCount; i++)
	{
		ConnCount;
		Connlist[i]->Savecon(file);
	}
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
		case EDIT_Label:
			pAct = new ActionEdit(this);
			break;
		case SAVE: 
			pAct = new ActionSave(this);
			break;
		case SIM_MODE:
			pAct = new Simulation(this);
			break;
		case ADD_ammeter:
			pAct = new ActionAmmeter(this);
			break;
		case LOAD: 
			pAct = new ActionLoad(this);
			break;
			//TODO: Create AddConection Action here
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
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(pUI);
		for (int i = 0; i < ConnCount; i++)
			Connlist[i]->Draw(pUI);

}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete pUI;
	
}
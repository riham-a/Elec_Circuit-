#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBulb.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddSwitch.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBattery.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddGround.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBuzzer.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddFuse.h"



ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
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
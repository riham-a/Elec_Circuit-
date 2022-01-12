#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"

#include "Actions\ActionAddRes.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBulb.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddSwitch.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBattery.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddGround.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddBuzzer.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddFuse.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddConnection.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionSelect.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionEdit.h"
#include <math.h>
#include"F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Simulation.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionLoad.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionSave.h"

#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionAddModule.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	int ConnCount; 
	Connection* Connlist[MaxCompCount - 1];
	UI* pUI; //pointer to the UI


public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();
	
	//Gets number of cmponents
	int getCompCount();  //Riham
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void AddConnection(Connection* pCon, Component* Comp1, Component* Comp2);
	// get compnent list
	Component** getCompList();
	int getCompCount();
	Component* Findcomp(int x , int y);
	Connection* Findconnection(int x, int y);
	void savef(fstream *file);

	void Bulb_to_Switch(); // feature 36: All bulbs in the circuit should be switched on / off according to switches states.

	//destructor
	~ApplicationManager();
};

#endif
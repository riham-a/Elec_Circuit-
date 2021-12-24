#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\ActionAddRes.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddBulb.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddSwitch.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddBattery.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddGround.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddBuzzer.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddFuse.h"
#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\ActionAddConnection.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ActionSelect.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ActionEdit.h"
//#include <math.h>
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ActionLoad.h"
#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ActionSave.h"
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

	//destructor
	~ApplicationManager();
};

#endif
#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
<<<<<<< Updated upstream

=======
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
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionLoad.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\ActionSave.h"
>>>>>>> Stashed changes
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

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
	

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
<<<<<<< Updated upstream
=======
	void AddConnection(Connection* pCon, Component* Comp1, Component* Comp2);
	// get compnent list
	Component** getCompList();
	Component* Findcomp(int x , int y);
	Connection* Findconnection(int x, int y);
	void savef(fstream *file);
>>>>>>> Stashed changes

	//destructor
	~ApplicationManager();
};

#endif
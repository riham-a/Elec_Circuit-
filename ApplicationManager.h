#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions\ActionAddRes.h"
#include "ActionAddBulb.h"
#include "ActionAddSwitch.h"
#include "ActionAddBattery.h"
#include "ActionAddGround.h"
#include "ActionAddBuzzer.h"
#include "ActionAddFuse.h"
#include "Actions\ActionAddConnection.h"
#include "Actions\ActionSelect.h"
#include "ActionEdit.h"
//#include <math.h>
#include "ActionLoad.h"
#include "ActionSave.h"
#include "ActionCopy.h"
#include "ActionPaste.h"
#include "ActionCut.h"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	Component* pCopied = nullptr;
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
	Component* Findcomp(int x , int y);
	Connection* Findconnection(int x, int y);
	void savef(ofstream *file);
	//void D_casting(const Component*compn);
	//Component* copyComponent(Component *);
	//void pasteComp();
	//Resistor* res;
	Component* forCopy(Component*, GraphicsInfo*);
	GraphicsInfo* changeGraphicInfo(int, int, GraphicsInfo*);
	//Component * forPaste();

	

	//destructor
	~ApplicationManager();
};

#endif
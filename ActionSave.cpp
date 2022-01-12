#include "ActionSave.h"
ActionSave::ActionSave(ApplicationManager* pApp): Action (pApp)
{
}

void ActionSave::Execute()
{
	// open file 
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Enter file name");
	string filename = pUI->GetSrting();
	ofstream file; 
	file.open(filename);
	pManager->savef(&file);
	file.close();
	pUI->ClearStatusBar();
}

void ActionSave::Undo()
{
}

void ActionSave::Redo()
{
}

ActionSave::~ActionSave(void)
{
}

#pragma once
#include "Actions/action.h"
#include "ApplicationManager.h"
//=======
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\Actions\Action.h"
//>>>>>>> Riham

//#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\applicationmanager.h"

//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\applicationmanager.h"
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\components\connection.h"
//class connection;
class actionedit : public Action
{
private:
	int x, y; // will be the inputs from mouse click 
	ApplicationManager* papp;
public:
	actionedit(ApplicationManager* papp);
	virtual void execute();
	virtual void undo();
	virtual void redo();
	virtual ~actionedit(void);
};
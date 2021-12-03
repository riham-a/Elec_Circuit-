#pragma once

#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Actions\Action.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Bulb.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\ApplicationManager.h"

class ActionAddBulb : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddBulb(ApplicationManager* pApp);
	virtual ~ActionAddBulb(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

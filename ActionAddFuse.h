#pragma once

#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Actions\Action.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\Fuse.h"
#include "f:\zc-university\y3\fall\c++\project\elec circuit code framework1\ApplicationManager.h"

class ActionAddFuse : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionAddFuse(ApplicationManager* pApp);
	virtual ~ActionAddFuse(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


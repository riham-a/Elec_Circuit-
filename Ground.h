#pragma once
<<<<<<< Updated upstream
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\Components\Component.h"

=======
#include "Components\Component.h"
>>>>>>> Stashed changes
class Ground :public Component
{
private:
	
public:
<<<<<<< Updated upstream
	Ground(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
=======
	static int Groundcount;
	int ground = -1;
	Ground(GraphicsInfo* b_GfxInfo);
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the resistor
	virtual void Save(fstream file);
	static int getGcount();
	static void setGcount(int s);
	virtual string CompData();
>>>>>>> Stashed changes

};

int Ground::Groundcount = 0;

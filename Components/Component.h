#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\UI/UI.h"
#include "Connection.h"


//Base class for all components (resistor, capacitor,....etc) .
class Component
{
private:
protected:
	string m_Label;
	double c_Value;
	string comptype;
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2
	bool selected;
	//Each terminal is connected to set of connections
	//Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	//Connection *term2_connections[MAX_CONNS];
	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;
	bool Selected;          //Riham  
	static int SID;
	int ID;

	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component

public:
	Component(GraphicsInfo *r_GfxInfo);
	//void setTerm1Volt(double v);		//sets the voltage at terminal1
	//void setTerm2Volt(double v);		//sets the voltage at terminal2
	//double getTerm1Volt();				//returns the voltage at terminal1
	//double getTerm2Volt();				//returns the voltage at terminal2

	virtual void Operate() = 0;	//Calculates the output voltage according to the inputs
	virtual void Draw(UI* ) = 0;	//for each component to Draw itself
	 
	//virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	//virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	//virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.

	Component();	

	//////////////////////////////////////////////////////
	bool IFSelected();  //riham
	void setSelected(bool s);
	virtual string CompData() = 0;
	////////////////////////////////////////////////////////
	GraphicsInfo* getM_pGfxInfo();  //riham
	////////////////////////////////////////////////////////

	void setSelected(bool);
	void setCompName(string s);
	virtual void setCompValue(double n); // virtual as when it come to be inherited, each component has a different value in different units like ohm for resistance and voltage for potential 
	string GetName();
	double GetValue();
	string Getcomptype();
	virtual void Save(fstream *file);
	int GetID();
	virtual void Load();
	//Destructor must be virtual
	virtual ~Component();
};
#endif

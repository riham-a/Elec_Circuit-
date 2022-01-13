#ifndef _COMPONENT_H
#define _COMPONENT_H
//#include "d:\zc\year3\fall 2021\c++\copy f my work\elec circuit code framework\ApplicationManager.h"
#include "..\Defs.h"
//#include "..\UI\UI.h"
//#include "D:\ZC\Year3\Fall 2021\C++\Copy f my work\Elec Circuit Code Framework\Components\Connection.h"
#include "F:\ZC-University\Y3\Fall\C++\Project\Elec Circuit Code Framework1\UI\UI.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include <fstream>

//#include "d:\zc\year3\fall 2021\c++\elec circuit code framework\elec circuit code framework\Components\Connection.h"
class ApplicationManager;
class Connection;
//Base class for all components (resistor, capacitor,....etc) .
//class ApplicationManager;
class Component
{
private:
protected:
	string m_Label;
	double c_Value;
	string comptype;
	//double volt;
	//double current;
	//Each component has two ending terminals (term1, term2)
	double term1_volt, term2_volt;	//voltage at terminals 1&2
	bool selected;
	//Each terminal is connected to set of connections
	Connection *term1_connections[MAX_CONNS]; //list of pointers to connections
	Connection *term2_connections[MAX_CONNS];
	int term1_conn_count;	//actual no. of connections to each terminal
	int term2_conn_count;
	//bool Selected;          //Riham  
	static int SID;
	int ID;
	GraphicsInfo *m_pGfxInfo;	//The parameters required to draw a component
	double volt = 0;
	double current = 0;
public:
	Component(GraphicsInfo *r_GfxInfo);

	/*void setcurrent(ApplicationManager* aptr);
	void setvolt(ApplicationManager* aptr);*/
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
	bool AddtoConnectionsTerm1(Connection* pC);
	bool AddtoConnectionsTerm2(Connection* pC);
	////////////////////////////////////////////////////////
	void setCompName(string s);
	//void setCompValue(double n); 
	//virtual string GetName();
	//virtual double GetValue();
	virtual void setCompValue(double n); // virtual as when it come to be inherited, each component has a different value in different units like ohm for resistance and voltage for potential 
	string GetName();
	void setcurrent(double c);
	void setvolt(double v);
	double GetValue();
	double Getcurrent();
	double Getvolt();
	string Getcomptype();
	virtual void Save(ofstream* file) =0;
	int GetID();
	virtual void Load();
	virtual Component* Copycomponent(GraphicsInfo* ginfo) = 0;
	//Destructor must be virtual

	void deleteComp_Conns();

	bool returnTerr1(Point* P);
	bool returnTerr2(Point* P);
	int gettermn1();
	int gettermn2();
	double getTerm1_volt();
	double getTerm2_volt();
	virtual ~Component();
};
#endif

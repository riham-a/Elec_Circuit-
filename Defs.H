#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_Switch_sim,
	ADD_voltmeter,
	ADD_ammeter,
	ADD_RESISTOR,		//Add a resistor
	ADD_Bulb,
	ADD_Switch,			//Add Switch
	ADD_Battery,
	ADD_Ground,
	ADD_Buzzer,
	ADD_Fuse,
	ADD_CONNECTION,		//Add Wire Connection
	ADD_Module,   		//Add Wire Connection
	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection
	COPY,
	PASTE,
	CUT,

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar

	DSN_TOOL,	//A click on an empty place in the design tool bar
	SIM_TOOL

};

enum  MODE	//Modes of operation
{

	DESIGN,
	SIMULATION
};

//Maximum number of connections that can be connected to any output components
#define MAX_CONNS 20




#endif
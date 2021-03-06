#include "UI.h"

UI::UI()
{
	AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	DrawColor = BLACK;
	SelectColor = BLUE;
	ConnColor = RED;
	MsgColor = BLUE;
	BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = new window(width, height, wx, wy);	


	ChangeTitle("Logic Simulator Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
}


int UI::getCompWidth() const
{
	return COMP_WIDTH;
}

int UI::getCompHeight() const
{
	return COMP_HEIGHT;
}

//======================================================================================//
//								Input Functions 										//
//======================================================================================//




void UI::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string UI::GetSrting()
{
	//Reads a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" is also supported
	//User should see what he is typing at the status bar


	string userInput;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);

		switch(Key)
		{
		case 27: //ESCAPE key is pressed
			PrintMsg("");
			return ""; //returns nothing as user has cancelled the input
		
		case 13:		//ENTER key is pressed
			return userInput;
		
		case 8:		//BackSpace is pressed
			if(userInput.size() > 0)
				userInput.resize(userInput.size() -1 );
			break;
		
		default:
			userInput+= Key;
		};
		
		PrintMsg(userInput);
	}

}

//This function reads the position where the user clicks to determine the desired action
ActionType UI::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if(AppMode == DESIGN )	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RES:	return ADD_RESISTOR;
			case ITM_Bulb:  return ADD_Bulb;
			case ITM_Switch:  return ADD_Switch;
			case ITM_Battery: return ADD_Battery;
			case ITM_Ground: return ADD_Ground;
			case ITM_Buzzer: return ADD_Buzzer;
			case ITM_Fuse: return ADD_Fuse;

			case ITM_Module: return ADD_Module;

			case ITM_EDIT: return EDIT_Label;
			case ITM_TO_SIM: return SIM_MODE;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_Connection: return ADD_CONNECTION;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_CUT: return CUT;
			case ITM_EXIT:	return EXIT;	
			case ITM_Delete: return DEL;
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
	
		//[2] User clicks on the drawing area
		if ( y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		int ClickedItemOrder = (x / ToolItemWidth);
		//Divide x coord of the point clicked by the menu item width (int division)
		//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

		switch (ClickedItemOrder)
		{
		case ITM_Switch_sim:	return ADD_Switch_sim;
		case ITM_voltmeter:  return ADD_voltmeter;
		case ITM_ammeter:  return ADD_ammeter;
		case ITM_EXIT_sim:	return EXIT;
		default: return SIM_TOOL;
			return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
		}
	}

}



//======================================================================================//
//								Output Functions										//
//======================================================================================//

//////////////////////////////////////////////////////////////////////////////////
void UI::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}


//////////////////////////////////////////////////////////////////////////////////
void UI::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, height-StatusBarHeight, width, height-StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(MsgColor); 
	pWind->DrawString(MsgX, height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void UI::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(MsgX, height - MsgY, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void UI::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void UI::CreateDesignToolBar() 
{
	AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_RES] = "images\\Menu\\Menu_Resistor.jpg";
	MenuItemImages[ITM_Bulb] = "images\\Menu\\Menu_Bulb.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_switch.jpg";
	MenuItemImages[ITM_Battery] = "images\\Menu\\Menu_Battery.jpg";
	MenuItemImages[ITM_Ground] = "images\\Menu\\Menu_Ground.jpg";
	MenuItemImages[ITM_Buzzer] = "images\\Menu\\Menu_Buzzer.jpg";
	MenuItemImages[ITM_Fuse] = "images\\Menu\\Menu_Fuse.jpg";

	MenuItemImages[ITM_Module] = "images\\Menu\\Menu_Module.jpg";

	MenuItemImages[ITM_EDIT] = "images\\Menu\\Ediit.jpg";
	MenuItemImages[ITM_TO_SIM] = "images\\Menu\\simulation.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Load.jpg";
	MenuItemImages[ITM_Fuse] = "images\\Menu\\Menu_Fuse.JPG";
	MenuItemImages[ITM_Connection] = "images\\Menu\\Connection.JPG";
	MenuItemImages[ITM_Delete] = "images\\Menu\\Delete.jpeg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\Copy.JPG";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\Paste.JPG";
	MenuItemImages[ITM_CUT] = "images\\Menu\\Cut.JPG";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*ToolItemWidth,0,ToolItemWidth, ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void UI::CreateSimulationToolBar()
{
	pWind->SetPen(BkGrndColor);
	pWind->SetBrush(BkGrndColor);
	//pWind->DrawRectangle(MsgX, height - MsgY, width, height);
	pWind->DrawRectangle(25, 0, width - ToolItemWidth, height - ToolBarHeight);
	
	AppMode = SIMULATION;	//Simulation Mode
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_CIRC_SIM] = "images\\Menu\\simulation.jpg";
	MenuItemImages[ITM_Switch_sim] = "images\\Menu\\switch_sim.jpg";
	MenuItemImages[ITM_ammeter] = "images\\Menu\\ammeter.jpg";
	MenuItemImages[ITM_voltmeter] = "images\\Menu\\voltmeter.jpg";
	MenuItemImages[ITM_EXIT_sim] = "images\\Menu\\Menu_Exit.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * ToolItemWidth, 0, ToolItemWidth, ToolBarHeight);
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);



	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void UI::DrawResistor(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	string ResImage;
	if(selected)	
		ResImage ="Images\\Comp\\Resistor_HI.jpg";	//use image of highlighted resistor
	else  
		ResImage = "Images\\Comp\\Resistor.jpg";	//use image of the normal resistor

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(ResImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
void UI::DrawBulb(const GraphicsInfo& b_GfxInfo,int on_off, bool selected) const
{
	string BulbImage;
	if (on_off == 1)
	{
		if (selected)
		{
			BulbImage = "Images\\Comp\\BulbON_HI.jpg";	//use image of highlighted Bulb
			pWind->DrawImage(BulbImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
		else
		{
			BulbImage = "Images\\Comp\\BulbON.jpg";	//use image of the normal Bulb
			pWind->DrawImage(BulbImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
	}
	else if (on_off == 0)
	{
		if (selected)
		{
			BulbImage = "Images\\Comp\\BulbOFF_HI.jpg";	//use image of highlighted Bulb
			pWind->DrawImage(BulbImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
		else
		{
			BulbImage = "Images\\Comp\\BulbOFF.jpg";	//use image of the normal Bulb
			pWind->DrawImage(BulbImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
	}
	else
	{
		PrintMsg( "Please, Enter only 1, or 0" );
	}
}


void UI::DrawModule(const GraphicsInfo& r_GfxInfo, bool selected) const
{
	string ModImage;
	if (selected)
		ModImage = "Images\\Comp\\Module_HI.jpg";	//use image of highlighted 
	else
		ModImage = "Images\\Comp\\Module.jpg";	//use image of the normal 

	
	pWind->DrawImage(ModImage, r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawSwitch(const GraphicsInfo& s_GfxInfo, int on_off, bool selected) const
{
	string SwitchImage;
	if (on_off == 1)
	{
		if (selected)
		{
			SwitchImage = "Images\\Comp\\SwitchOFF_HI.jpg";	//use image of highlighted Switch
			pWind->DrawImage(SwitchImage, s_GfxInfo.PointsList[0].x, s_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
		else
		{
			SwitchImage = "Images\\Comp\\SwitchOFF.jpg";	//use image of the normal Switch
			pWind->DrawImage(SwitchImage, s_GfxInfo.PointsList[0].x, s_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
	}
	else if (on_off == 0)
	{
		if (selected)
		{
			SwitchImage = "Images\\Comp\\SwitchON_HI.jpg";	//use image of highlighted Switch
			pWind->DrawImage(SwitchImage, s_GfxInfo.PointsList[0].x, s_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
		else
		{
			SwitchImage = "Images\\Comp\\SwitchON.jpg";	//use image of the normal Switch
			pWind->DrawImage(SwitchImage, s_GfxInfo.PointsList[0].x, s_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
		}
	}
	else
	{
		PrintMsg(" Please Enter only 0 or 1");
	}
}

void UI::DrawBattery(const GraphicsInfo& b_GfxInfo, bool selected) const
{
	string BatteryImage;
	if (selected)
		BatteryImage = "Images\\Comp\\Battery_HI.jpg";	
	else
		BatteryImage = "Images\\Comp\\Battery.jpg";	

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(BatteryImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawGround(const GraphicsInfo& b_GfxInfo, bool selected) const
{
	string GroundImage;
	if (selected)
		GroundImage = "Images\\Comp\\Ground_HI.jpg";
	else
		GroundImage = "Images\\Comp\\Ground.jpg";

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(GroundImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}

void UI::DrawBuzzer(const GraphicsInfo& b_GfxInfo, bool selected) const
{
	string BuzzerImage;
	if (selected)
		BuzzerImage = "Images\\Comp\\Buzzer_HI.jpg";
	else
		BuzzerImage = "Images\\Comp\\Buzzer.jpg";

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(BuzzerImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}



void UI::DrawFuse(const GraphicsInfo& b_GfxInfo, bool selected) const
{
	string FuseImage;
	if (selected)
		FuseImage = "Images\\Comp\\Fuse_HI.jpg";
	else
		FuseImage = "Images\\Comp\\Fuse.jpg";

	//Draw Resistor at Gfx_Info (1st corner)
	pWind->DrawImage(FuseImage, b_GfxInfo.PointsList[0].x, b_GfxInfo.PointsList[0].y, COMP_WIDTH, COMP_HEIGHT);
}
//TODO: Add similar functions to draw all other components




void UI::DrawConnection(const GraphicsInfo &r_GfxInfo, bool selected) const
{
	//string FuseImage;
	if (selected)
		pWind->SetPen(RED, 5);
	else
		pWind->SetPen(BLUE, 5);
		pWind->DrawLine(r_GfxInfo.PointsList[0].x, r_GfxInfo.PointsList[0].y, r_GfxInfo.PointsList[1].x, r_GfxInfo.PointsList[1].y);
}
window* UI::getPWind()
{
	return pWind;
}

UI::~UI()
{
	delete pWind;
}
//#include "ActionAddConnection.h"
//
//#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"
//
//ActionAddConnection::ActionAddConnection(ApplicationManager* pApp) :Action(pApp)
//{
//}
//
//ActionAddConnection::~ActionAddConnection(void)
//{
//}
//
//void ActionAddConnection::Execute()
//{
//	int Counter = 0;
//	int Counter2 = 0;
//	//Get a Pointer to the user Interfaces
//	UI* pUI = pManager->GetUI();
//
//	//Print Action Message
//	pUI->PrintMsg("Adding a new connection: Click at the terminal of the First Component");
//
//	//Get Center point of the area where the Comp should be drawn
//	pUI->GetPointClicked(x1, y1);
//	/////////////////////////////////////////////////////////////////////////
//	for (int i = 0; i < pManager->getCompCount(); i++)
//	{
//		Component* C1 = pManager->getCompList()[i];
//		int X1 = C1->getM_pGfxInfo()->PointsList[0].x;
//		int Y1 = C1->getM_pGfxInfo()->PointsList[0].y;
//		int X2 = X1 + pUI->getCompWidth();
//		int Y2 = Y1 + pUI->getCompHeight();
//		if ((x1 < X1 + 20) && (x1 > X1 - 20) && (y1 < Y2) && (y1 > Y1))
//		{
//			Comp2 = C1;
//			//Clear Status Bar
//			pUI->ClearStatusBar();
//
//			//Print Action Message
//			pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");
//			break;
//		}
//
//	}
//	pUI->GetPointClicked(x2, y2);
//	for (int i = 0; i < pManager->getCompCount(); i++)
//	{
//		Component* C2 = pManager->getCompList()[i];
//		int X1 = C2->getM_pGfxInfo()->PointsList[0].x;
//		int Y1 = C2->getM_pGfxInfo()->PointsList[0].y;
//		int X2 = X1 + pUI->getCompWidth();
//		int Y2 = Y1 + pUI->getCompHeight();
//		if ((x2 < X2 + 20) && (x2 > X2 - 20) && (y2 < Y2) && (y2 > Y1))
//		{
//			Comp1 = C2;
//			//Clear Status Bar
//			pUI->ClearStatusBar();
//
//			//Print Action Message
//			pUI->PrintMsg("Connection is done succesfuly");
//			break;
//		}
//
//	}
//	// ////////////////////////////////////////////////////////////////////////
//	//Clear Status Bar
//	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
//
//	pGInfo->PointsList[0].x = x1;
//	pGInfo->PointsList[0].y = y1;
//	pGInfo->PointsList[1].x = x2;
//	pGInfo->PointsList[1].y = y2;
//
//	Connection* pC = new Connection(pGInfo, Comp1, Comp2);
//	pManager->AddConnection(pC, Comp1, Comp2);   /// Adding new connection
//}
//
//void ActionAddConnection::Undo()
//{}
//
//void ActionAddConnection::Redo()
//{}
//
//
/////////////////////////////////////////////////////////////////////
//#include "ActionAddConnection.h"
//
//#include "D:\ZC\Year3\Fall 2021\C++\Elec Circuit Code Framework\Elec Circuit Code Framework\ApplicationManager.h"
//
//ActionAddConnection::ActionAddConnection(ApplicationManager* pApp/*, Component* comp1, Component* comp2*/) :Action(pApp)
//{
//}
//
//ActionAddConnection::~ActionAddConnection(void)
//{
//}
//
//void ActionAddConnection::Execute()
//{
//	int Counter = 0;
//	int Counter2 = 0;
//	//Get a Pointer to the user Interfaces
//	UI* pUI = pManager->GetUI();
//
//	//Print Action Message
//	pUI->PrintMsg("Adding a new connection: Click at the terminal of the First Component");
//
//	//Get Center point of the area where the Comp should be drawn
//	pUI->GetPointClicked(x1, y1);
//	/////////////////////////////////////////////////////////////////////////
//	for (int i = 0; i < pManager->getCompCount(); i++)
//	{
//
//		Component* C1 = pManager->getCompList()[i];
//		int X1 = C1->getM_pGfxInfo()->PointsList[0].x;
//		int Y1 = C1->getM_pGfxInfo()->PointsList[0].y;
//		int X2 = X1 + pUI->getCompWidth();
//		int Y2 = Y1 + pUI->getCompHeight();
//		if ((x1 < X1 + 20) && (x1 > X1 - 20) && (y1 < Y2) && (y1 > Y1))
//		{
//			Comp2 = C1;
//			//Clear Status Bar
//			pUI->ClearStatusBar();
//
//			//Print Action Message
//			pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");
//
//			//Get Center point of the area where the Comp should be drawn
//			pUI->GetPointClicked(x2, y2);
//			for (int j = 0; j < pManager->getCompCount(); j++)
//			{
//
//				Component* C2 = pManager->getCompList()[j];
//				int X1 = C2->getM_pGfxInfo()->PointsList[0].x;
//				int Y1 = C2->getM_pGfxInfo()->PointsList[0].y;
//				int X2 = X1 + pUI->getCompWidth();
//				int Y2 = Y1 + pUI->getCompHeight();
//				if (((x2 > X2 - 20) && (x2 < X2 + 20) && (y1 < Y2) && (y1 > Y1)) || ((x2 > X1 - 20) && (x2 < X1 + 20) && (y1 < Y2) && (y1 > Y1)))
//				{
//					Comp1 = C2;
//					pUI->PrintMsg("Connection done successfully!");
//				}
//				else
//				{
//					/*pUI->PrintMsg("Please, Click at a valid terminal");
//					j--;
//					pUI->GetPointClicked(x2, y2);
//					continue;
//					*/
//					Counter2++;
//				}
//				if (Counter2 == pManager->getCompCount() - 1)
//				{
//					pUI->PrintMsg("Please, Click at a valid terminal");
//					//j--;
//					j = -1;
//					pUI->GetPointClicked(x2, y2);
//					Counter2 = 0;
//					continue;
//				}
//
//			}
//		}
//		else if ((x1 > X2 - 20) && (x1 < X2 + 20) && (y1 < Y2) && (y1 > Y1))
//		{
//			Comp1 = C1;
//			//Clear Status Bar
//			pUI->ClearStatusBar();
//
//			//Print Action Message
//			pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");
//
//			//Get Center point of the area where the Comp should be drawn
//			pUI->GetPointClicked(x2, y2);
//			for (int j = 0; j < pManager->getCompCount(); j++)
//			{
//
//				Component* C2 = pManager->getCompList()[j];
//				int X1 = C2->getM_pGfxInfo()->PointsList[0].x;
//				int Y1 = C2->getM_pGfxInfo()->PointsList[0].y;
//				int X2 = X1 + pUI->getCompWidth();
//				int Y2 = Y1 + pUI->getCompHeight();
//				if (((x2 > X2 - 20) && (x2 < X2 + 20) && (y1 < Y2) && (y1 > Y1)) || ((x2 > X1 - 20) && (x2 < X1 + 20) && (y1 < Y2) && (y1 > Y1)))
//				{
//					Comp2 = C2;
//					pUI->PrintMsg("Connection done successfully!");
//				}
//				else
//				{
//					/*
//					pUI->PrintMsg("Please, Click at a valid terminal");
//					j--;
//					pUI->GetPointClicked(x2, y2);
//					continue;
//					*/
//					Counter2++;
//				}
//				if (Counter2 == pManager->getCompCount() - 1)
//				{
//					pUI->PrintMsg("Please, Click at a valid terminal");
//					//j--;
//					j = -1;
//					pUI->GetPointClicked(x2, y2);
//					Counter2 = 0;
//					continue;
//				}
//
//			}
//		}
//		else
//		{
//			/*pUI->PrintMsg("Please, Click at a valid terminal");
//			i--;
//			pUI->GetPointClicked(x1, y1);
//			continue;
//			*/
//			Counter++;
//		}
//		if (Counter == pManager->getCompCount() - 1)
//		{
//			pUI->PrintMsg("Please, Click at a valid terminal");
//			//i--;
//			i = -1;
//			pUI->GetPointClicked(x1, y1);
//			Counter = 0;
//			//continue;
//		}
//	}
//	// ////////////////////////////////////////////////////////////////////////
//	//Clear Status Bar
//	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
//
//	pGInfo->PointsList[0].x = x1;
//	pGInfo->PointsList[0].y = y1;
//	pGInfo->PointsList[1].x = x2;
//	pGInfo->PointsList[1].y = y2;
//
//	Connection* pC = new Connection(pGInfo, Comp1, Comp2);
//	pManager->AddConnection(pC, Comp1, Comp2);   /// Adding new connection
//}
//
//void ActionAddConnection::Undo()
//{}
//
//void ActionAddConnection::Redo()
//{}
//
//////////////////////////NEW
/*void ActionAddConnection::Execute()
{
		int Counter = 0;
		int Counter2 = 0;
		//Get a Pointer to the user Interfaces
		UI* pUI = pManager->GetUI();
	
		//Print Action Message
		pUI->PrintMsg("Adding a new connection: Click at the terminal of the First Component");
	
		//Get Center point of the area where the Comp should be drawn
		pUI->GetPointClicked(x1, y1);
		/////////////////////////////////////////////////////////////////////////
		//for (int i = 0; i < pManager->getCompCount(); i++)
		//{
	
		//	Component* C1 = pManager->getCompList()[i];
		//	int X1 = C1->getM_pGfxInfo()->PointsList[0].x;
		//	int Y1 = C1->getM_pGfxInfo()->PointsList[0].y;
		//	int X2 = X1 + pUI->getCompWidth();
		//	int Y2 = Y1 + pUI->getCompHeight();
		//	if ((x1 < X1 + 20) && (x1 > X1 - 20) && (y1 < Y2) && (y1 > Y1))
		//	{
		//		Comp2 = C1;
		//		//Clear Status Bar
		//		pUI->ClearStatusBar();
	
		//		//Print Action Message
		//		pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");
	
		//		//Get Center point of the area where the Comp should be drawn
		//		pUI->GetPointClicked(x2, y2);
		//		for (int j = 0; j < pManager->getCompCount(); j++)
		//		{
	
		//			Component* C2 = pManager->getCompList()[j];
		//			int X1 = C2->getM_pGfxInfo()->PointsList[0].x;
		//			int Y1 = C2->getM_pGfxInfo()->PointsList[0].y;
		//			int X2 = X1 + pUI->getCompWidth();
		//			int Y2 = Y1 + pUI->getCompHeight();
		//			if (((x2 > X2 - 20) && (x2 < X2 + 20) && (y1 < Y2) && (y1 > Y1)) || ((x2 > X1 - 20) && (x2 < X1 + 20) && (y1 < Y2) && (y1 > Y1)))
		//			{
		//				Comp1 = C2;
		//				pUI->PrintMsg("Connection done successfully!");
		//			}
		//			else
		//			{
		//				/*pUI->PrintMsg("Please, Click at a valid terminal");
		//				j--;
		//				pUI->GetPointClicked(x2, y2);
		//				continue;
		//				*/
		//				Counter2++;
		//			}
		//			if (Counter2 == pManager->getCompCount() - 1)
		//			{
		//				pUI->PrintMsg("Please, Click at a valid terminal");
		//				//j--;
		//				j = -1;
		//				pUI->GetPointClicked(x2, y2);
		//				Counter2 = 0;
		//				continue;
		//			}

		//		}
		//	}
		//	else if ((x1 > X2 - 20) && (x1 < X2 + 20) && (y1 < Y2) && (y1 > Y1))
		//	{
		//		Comp1 = C1;
		//		//Clear Status Bar
//pUI->ClearStatusBar();

//		//Print Action Message
	//pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");

//		//Get Center point of the area where the Comp should be drawn
//		pUI->GetPointClicked(x2, y2);
//		for (int j = 0; j < pManager->getCompCount(); j++)
//		{

//			Component* C2 = pManager->getCompList()[j];
//			int X1 = C2->getM_pGfxInfo()->PointsList[0].x;
//			int Y1 = C2->getM_pGfxInfo()->PointsList[0].y;
//			int X2 = X1 + pUI->getCompWidth();
//			int Y2 = Y1 + pUI->getCompHeight();
//			if (((x2 > X2 - 20) && (x2 < X2 + 20) && (y1 < Y2) && (y1 > Y1)) || ((x2 > X1 - 20) && (x2 < X1 + 20) && (y1 < Y2) && (y1 > Y1)))
//			{
//				Comp2 = C2;
//				pUI->PrintMsg("Connection done successfully!");
//			}
//			else
//			{
//				/*
//				pUI->PrintMsg("Please, Click at a valid terminal");
//				j--;
			//pUI->GetPointClicked(x2, y2);
//				continue;
//				*/
//				Counter2++;
//			}
//			if (Counter2 == pManager->getCompCount() - 1)
//			{
//				pUI->PrintMsg("Please, Click at a valid terminal");
//				//j--;
//				j = -1;
//				pUI->GetPointClicked(x2, y2);
//				Counter2 = 0;
//				continue;
//			}

//		}
//	}
//	else
//	{
//		/*pUI->PrintMsg("Please, Click at a valid terminal");
//		i--;
//		pUI->GetPointClicked(x1, y1);
//		continue;
//		*/
//		Counter++;
//	}
//	if (Counter == pManager->getCompCount() - 1)
//	{
//		pUI->PrintMsg("Please, Click at a valid terminal");
//		//i--;
//		i = -1;
//		pUI->GetPointClicked(x1, y1);
//		Counter = 0;
//		//continue;
//	}
//}
// ////////////////////////////////////////////////////////////////////////
//Clear Status Bar
//Component* C1 = pManager->Findcomp(x1, y1);
//Point* P1 = new Point();
//P1->x = x1; P1->y = y1;
//Point* P2 = new Point();
//P2->x = x2; P2->y = y2;
//if (C1)
//{
//	pUI->PrintMsg("Please, Click at a valid componentHHHH");
//	pUI->GetPointClicked(x1, y1);
//}
//else
//{
//	pUI->PrintMsg("Gamed ya Reeeee");
//	if (C1->returnTerr1(P1))
//	{
//		Comp1 = C1;
//	}
//	else if (C1->returnTerr1(P2))
//	{
//		Comp2 = C1;
//	}
//	else
//	{
//		pUI->PrintMsg("This Component exceeds its maximum number of connections");
//	}
//	pUI->PrintMsg("Adding a new connection: Click at the terminal of the Second Component");
//}
//
//Component* C2 = pManager->Findcomp(x2, y2);
//if (C2 != nullptr)
//{
//	if (C2->returnTerr1(P1))
//	{
//		Comp1 = C2;
//	}
//	else if (C2->returnTerr1(P2))
//	{
//		Comp2 = C2;
//	}
//	else
//	{
//		pUI->PrintMsg("This Component exceeds its maximum number of connections");
//	}
//
//}
//else
//{
//	pUI->PrintMsg("Please, Click at a valid component");
//}
//}
//
//
//GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the connection
//
///*pGInfo->PointsList[0].x = Comp1->getM_pGfxInfo()->PointsList[0].x;
//pGInfo->PointsList[0].y = Comp1->getM_pGfxInfo()->PointsList[0].y;
//pGInfo->PointsList[1].x = Comp2->getM_pGfxInfo()->PointsList[1].x;
//pGInfo->PointsList[1].y = Comp2->getM_pGfxInfo()->PointsList[1].y;
//*/
//pGInfo->PointsList[0].x = x1;
//pGInfo->PointsList[0].y = y1;
//pGInfo->PointsList[1].x = x2;
//pGInfo->PointsList[1].y = y2;
//if ((Comp1 && Comp2) && (Comp1 != Comp2))
//{
//	Connection* pC = new Connection(pGInfo, Comp1, Comp2);
//	pManager->AddConnection(pC, Comp1, Comp2);   /// Adding new connection
//	Comp1->AddtoConnectionsTerm1(pC);
//	Comp2->AddtoConnectionsTerm2(pC);
//	pUI->ClearStatusBar();
//	pUI->PrintMsg("Connection done successfully!");
//}
//}*/

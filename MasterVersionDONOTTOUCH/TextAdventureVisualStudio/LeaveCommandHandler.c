/******************************************************************************
filename    LeaveCommandHandler.c
author      Jordan Driscoll
DP email    jordan.driscoll@digipen.edu
course      Video Game Design ** Do not use this code in your team project

Brief Description:
This file declares functions that handles the "leave" user command, which outputs
a description of an item or the current room.

******************************************************************************/
#include "stdafx.h"
#include "LeaveCommandHandler.h"
#include "GameState.h"
#include "ItemList.h"
#include "Room.h"
#include "WorldData.h"
#include "CommandData.h"
#include "CellKeyFunctions.h"



/* Handles the "leave" command, which outputs a list of the items in the player's inventory */
void HandleLeaveCommand(CommandData* command, GameState *gameState, WorldData *worldData)
{

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(command);
	/*FOR NOW, if he says thsi he picks up the key*/
	Room* room; 
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	/*if he's in the 0th room */
	if (gameState->currentRoomIndex == 0) {
		/*If he doesn't have the key*/
		if (!ItemList_FindItem(*Room_GetItemList(room), "cell keys")) {
			printf("The Door's Locked");
		}
		else {
			printf("You're freeeeeeeeeeeeeeeeeeeeeeeeee");
		}
	
		
	}
}
/******************************************************************************
filename    ScreamCommandHandler.c
author      Jordan Driscoll
DP email    jordan.driscoll@digipen.edu
course      Video Game Design ** Do not use this code in your team project

Brief Description:
This file declares functions that handles the "leave" user command, which outputs
a description of an item or the current room.

******************************************************************************/

#include "stdafx.h"
#include "DanceCommandHandler.h"
#include "GameState.h"
#include "ItemList.h"
#include "Room.h"
#include "WorldData.h"
#include "CommandData.h"
#include "GameFlags.h" /* GameFlags_IsInList */
#include "CellKeyFunctions.h"




/* Handles the "leave" command, which outputs a list of the items in the player's inventory */
void HandleDanceCommand(CommandData* command, GameState *gameState, WorldData *worldData)
{

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(command);
	/*FOR NOW, if he says thsi he picks up the key*/
	Room* room;
	ItemList** roomItemsPtr; /* The list of items in the current room */

	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	roomItemsPtr = Room_GetItemList(room);
	if (GameFlags_IsInList(gameState->gameFlags, "guardEntered")) {
		printf("You Square Dance with the guard, amid dancing, you pick pocket his keys.");
		ItemList_AddItem(roomItemsPtr, CellKey_Build());
	}
	else {
		printf("You boogy down and have a wacky good time");
	}
}
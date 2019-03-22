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
#include "ScreamCommandHandler.h"
#include "GameState.h"
#include "ItemList.h"
#include "Room.h"
#include "WorldData.h"
#include "CommandData.h"
#include "DanceCommandHandler.h"
#include "GameFlags.h" /* GameFlags_IsInList */



/* Handles the "leave" command, which outputs a list of the items in the player's inventory */
void HandleScreamCommand(CommandData* command, GameState *gameState, WorldData *worldData)
{

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(command);
	/*FOR NOW, if he says thsi he picks up the key*/
	Room* room;
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	/*if he's in the 0th room */
	if (gameState->currentRoomIndex == 0) {
		/*If he doesn't have the key*/
		printf("The guard entered to see the problem");
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "guardEntered");

	}
}
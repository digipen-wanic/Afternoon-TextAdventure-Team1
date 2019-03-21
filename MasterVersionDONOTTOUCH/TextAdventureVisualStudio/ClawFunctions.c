/******************************************************************************
filename    ClawFunctions.c
author      Cory Carlson
DP email    cory.carlson@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "claw".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "ClawFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the claw is taken. */

void Claw_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the claw might be used, whenever it is picked up. */
	printf("This claw could be useful in a fight.\n");
}


/* Helper: The action performed when the claw is used. */
void Claw_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */

	Item* claw; /* The claw in the player's inventory */

				 /* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the claw out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the claw - inform the user of the problem and take no action */
		printf("You must have the claw before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 8)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the claw here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "GuardsGoneScored"))
	{
		/* the player already used the claw - inform the user of the problem and take no action */
		printf("You already used the claw here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);


		/* Find the claw in the player's inventory - it should be there, since we are in the Inventory context */
		claw = ItemList_FindItem(gameState->inventory, "claw");

		/* Remove the claw from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, claw);

		/* Tell the user what they did */
		printf("You defeat the two Boarhounds with the claw. You gain 10 XP and 2 G, or you would if this was an RPG.\n");
		Room_AddRoomExit(room, "north", 10);

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 1);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "You are in the Garden. There is a gate to the NORTH. There are no more guards.\n");


		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "GuardsGoneScored");
	}
}


/* Build a "claw" object */
Item* Claw_Build()
{
	/* Create a "claw" item, using the functions defined in this file */
	return Item_Create("claw", "A strong metal claw used by bear warriors in war.", true, Claw_Use, Claw_Take, NULL, NULL);
}
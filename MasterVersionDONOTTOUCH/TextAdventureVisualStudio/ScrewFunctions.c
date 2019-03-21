/******************************************************************************
filename    ScrewFunctions.c
author      Cory Carlson
DP email    cory.carlson@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "screw".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "ScrewFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */


/* Helper: The action performed when the screw is taken. */

void Screw_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the screw might be used, whenever it is picked up. */
	printf("This screwdriver could help you undo screws.\n");
}


/* Helper: The action performed when the screw is used. */
void Screw_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	Item* screw; /* The screw in the player's inventory */

				/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the screw out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the screw - inform the user of the problem and take no action */
		printf("You must have the screwdriver before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 10)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the screwdriver here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "VentOpenedScored"))
	{
		/* the player already used the screw - inform the user of the problem and take no action */
		printf("You already used the screwdriver here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);


		/* Find the screw in the player's inventory - it should be there, since we are in the Inventory context */
		screw = ItemList_FindItem(gameState->inventory, "screw");

		/* Remove the screw from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, screw);

		/* Tell the user what they did */
		printf("You take the screwdriver and bash it against the vent. You strike it with such force the entire wall breaks down. The screwdriver breaks too.\n");
		Room_AddRoomExit(room, "east", 12);

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 1);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "You are in the Executive Bathroom. There is no longer an eastern wall.\n");


		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "VentOpenedScored");
	}
}


/* Build a "screw" object */
Item* Screw_Build()
{
	/* Create a "screw" item, using the functions defined in this file */
	return Item_Create("screw", "A normal screwdriver.", true, Screw_Use, Screw_Take, NULL, NULL);
}
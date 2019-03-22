/******************************************************************************
filename    cell keyFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "cell key".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "CellKeyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */




/* Helper: The action performed when the cell key is taken. */
void CellKey_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* Give the user a hint about how the cell key might be used, whenever it is picked up. */
	printf("The cell key feels heavy in your hand.\n");
}


/* Helper: The action performed when the cell key is used. */
void CellKey_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* CellKey; /* The cell key in the player's inventory */

				 /* safety check on the parameters */

	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the cell key out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the cell key - inform the user of the problem and take no action */
		printf("You must have the cell key before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the cell key here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "DoorOpenedScored"))
	{
		/* the player already used the cell key - inform the user of the problem and take no action */
		printf("You already used the cell key here.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the cell key in the player's inventory - it should be there, since we are in the Inventory context */
		CellKey = ItemList_FindItem(gameState->inventory, "cell key");

		/* Remove the cell key from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, CellKey);

		/* Tell the user what they did */
		printf("You smash the cage open with the cell key, and the cell key crumbles.  You can now reach the small egg inside.\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 1);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");

		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "DoorOpenedScored");
	}
}


/* Build a "cell key" object */
Item* CellKey_Build()
{
	/* Create a "cell key" item, using the functions defined in this file */
	return Item_Create("cell key", "A small red cell key of indeterminate origin", true, CellKey_Use, CellKey_Take, NULL, NULL);
}
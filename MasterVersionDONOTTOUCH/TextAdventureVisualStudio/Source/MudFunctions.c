#include "stdafx.h"
#include "GoldPieceFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "WorldData.h" /* WorldData_GetRoom */
#include "Item.h"
#include "Room.h"
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "BookOfLoreFunctions.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the gold piece is taken. */
void Mud_Look(int context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	Room* room; /* The current room */

	/* check if the gold piece has already been scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "bookRevealed"))
	{
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		/* tell the user that something cool happens when they pick up the gold piece */
		printf("Oh shoot, there's a book of linguistics in this here mud!\n");
		printf("There so much valuable informations about the Chickish language!\n");
		printf("You can now speak Chickish at a conversational level.\n\n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 5);
		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "bookRevealed");
		ItemList_AddItem(Room_GetItemList(room), BookOfLore_Build());
		
	}
}

/* Build a "claw" object */
Item* Mud_Build()
{
	/* Create a "claw" item, using the functions defined in this file */
	return Item_Create("mud", "some mud", false, NULL, NULL, NULL, NULL);
}
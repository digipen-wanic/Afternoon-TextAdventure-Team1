#include "stdafx.h" /* NULL, printf */
#include "TakeCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Add, ItemList_Remove */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */

void HandleSpeakCommand(CommandData *command, GameState* gameState, WorldData* worldData)
{
	Item* speakee; /* who or what is being spoken to */
	Room* room; /* the current room */
	ItemList** roomItemPtr; /* the list of items in the current room */
	ItemFunc speakFunc; /* The function to be called for the given item when it is spoken to */
	CommandContext speakContext = CommandContext_User; /* the context used for the "use" function*/
	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the current room's item list */
	roomItemPtr = Room_GetItemList(room);
	if (roomItemPtr == NULL)
	{
		return; /* there was no room or item list pointer - something is wrong.  take no action */
	}

	/* find the item in the current room's item list, using the command noun */
	speakee = ItemList_FindItem(*roomItemPtr, command->noun);
	if (speakee == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.\n", command->noun);
		return;
	}
	/* retrieve the current room */	
	printf("You speak to the %s\n", command->noun);

	speakFunc = Item_GetSpeakFunc(speakee);
	if (speakFunc == NULL)
	{
		/* no "use" function was defined, so the item cannot be used - inform the user of the problem and take no action*/
		printf("Sadly, you hear no response.");
		return;
	}

	speakFunc(speakContext, gameState, worldData);
}
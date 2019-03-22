/*
ProleHenFunction.c

This file was made by: Yuval gang
Brief: The chicken is an NPC which is also an item. She is the border agent that decides whether or not you go through

*/

#include "stdafx.h"
#include "GoldPieceFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the gold piece is taken. */
void ProleHen_Speak(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	char dialogueChoice;
	/*int addressGuess;*/
	int hasBook = true;
	/* -1 means upset, 0 means cordial, 1 means satisfied. works really nicely for score multiplier at the end of the encounter, and 1 means the player can proceed.*/
	int henEmotion = 0;
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	if (GameFlags_IsInList(gameState->gameFlags, "hasBook"))
	{
		hasBook = true;
	}

	if (!GameFlags_IsInList(gameState->gameFlags, "henSpokenTo"))
	{
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		/* tell the user that something cool happens when they pick up the gold piece */
		printf("[Prole Hen] \"Bok bok bawk bok, bock bokk boke. Bawk!\"");
		if (hasBook)
		{
			printf(" (Welcome to the Beargarian-Chickish border, strange-feathered one. Present your passport!)");
		}
		printf("\n\n");

		printf("How do you wish to respond?\n");
		printf("1 - \"Bok bok, bawk bok bock\"");
		if (hasBook)
			printf(" (Chicken so great, passport not required)");
		printf("\n");

		printf("2 - \"Bawk, bok bok-ock bawk bok\"");
		if (hasBook)
			printf(" (You misunderstand, I have residency in Chicken)");
		printf("\n");

		printf("3 - \"Bork\"");
		if (hasBook)
			printf(" (Extremely offensive slur)");
		printf("\n");
		

		dialogueChoice = (char) getchar();
		getchar();


		if (dialogueChoice == '1')
		{
			printf("\"Bokka bok bok\"");
			if (hasBook)
				printf(" (A passport is required)");
			printf("\n");
		}			
		else if (dialogueChoice == '3')
		{
			printf("\"BOK BOK BOK BOK BOK BOK! BAWK BAWKA 'BORK' BOK BOKKA BOK BAWK BOK! BOK!\"");
			if (hasBook)
			{
				printf(" (HOLD UP HOLD UP HOLD UP! YOU THINK YOU CAN CALL ME 'BORK' IN MY OWN COUNTRY? DISGUSTING!)");
			}
			printf("\n");
			henEmotion = -1;
		}

		/* this needs to be fleshed out but it's literally 4:44 am rn */
		else if(dialogueChoice == '2')
		{
			printf("\"Bock, bok bokk bock. Bawk ba-bock.\"");
			if (hasBook)
			{
				printf(" (Oh, you should have said so. Proceed through the gate.)");
			}
			printf("\n");
			henEmotion = 1;
			Room_AddRoomExit(room, "gate", 6);
		}

		else
		{
			printf("\"Bok bawk!\"");
			if (hasBook)
				printf(" (Nonsense!)");
			printf("\n");
		}
		
		/* add or subtract to the user's score */
		GameState_ChangeScore(gameState, 5 * henEmotion);
		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "henSpokenTo");
	}
}

/* Build a "gold piece" object */
Item* ProleHen_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("prole hen", "a working class hen from the outskirts of Chicken\n", true, NULL, NULL, NULL, ProleHen_Speak);
}
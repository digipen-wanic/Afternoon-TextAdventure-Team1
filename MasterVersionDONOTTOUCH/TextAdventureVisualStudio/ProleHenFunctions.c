/*
ProleHenFunction.c

This file was made by: Yuval gang
Brief: The chicken is an NPC which is also an item. She is the border agent that decides whether or not you go through

3/25/2019

*/

#include "stdafx.h"
#include "GoldPieceFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the hen is spoken to. */
void ProleHen_Speak(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	char dialogueChoice;
	/*int addressGuess;*/
	int hasBook = false;
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

	if (!(GameFlags_IsInList(gameState->gameFlags, "passedConvo") && hasBook))
	{
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		/* a fun conversation */
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
		/* s/o to me in the past from me in the present, it's 4:54 am here */
		/* by the way this allows you through the gate, and sets the score multiplier positive */
		else if(dialogueChoice == '2')
		{
			printf("\"Bock, bok bokk bock. Bawk ba-bock.\"");
			if (hasBook)
			{
				printf(" (Oh, you should have said so. Proceed through the gate.)");
			}
			printf("\n");
			henEmotion = 1;
			gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "passConvo");
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
		if(!(GameFlags_IsInList(gameState->gameFlags, "passedConvo")))
			GameState_ChangeScore(gameState, 5 * henEmotion);
	}
}

/* Build a "prole hen" object */
Item* ProleHen_Build()
{
	/* Create a "prole hen" item, using the functions defined in this file */
	return Item_Create("prole hen", "a working class hen from the outskirts of Chicken\n", true, NULL, NULL, NULL, ProleHen_Speak);
}
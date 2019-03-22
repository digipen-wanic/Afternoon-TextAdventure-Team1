/******************************************************************************
filename    Room0_Build()
author      Jordan Driscoll
DP email    jordan.driscoll@digipen.edu
course      Video Game Programming 100

Brief Description:
This is the room that you begin at, it will lead you to either room to or room 3

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */
#include "ClawFunctions.h" /* Claw_Build */
#include "ScrewFunctions.h" /* Screw Build */
#include "ProleHenFunctions.h" /* ProleHen build */
#include "MudFunctions.h" /*mud*/
#include "BookOfLoreFunctions.h" /*book*/




/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	

	/* Return the new room */
	return room;
}


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	
	/* Pre-declare a room pointer which we will use to build the new room */
	/*Don't bother changing this*/ 
	Room* room = NULL;
	
	/* TODO REQUIRED: Call Room_Create with the Room 1 description:	*/
	/*You are a bear trapped in Beargarian prison.You have recently been detained for attempted murder in the bordering country of Chicken.After being declawed, your goal is now to escape the prison, immigrate to Chicken, and murder the Top Bawk at the Capital.*/
	room = Room_Create("You find yourself in a chambear, your paws are sore from being declawed.");

	/*Time to write out everything that happens in the room*/
	
	/*User types: leave, escape, go anywhere*/

		/*The doors locked*/
	
	/*User types search*/
		/*Say: You find a fur sharpener*/
	
	/*User types dance*/
		/*You boogey down, which ultimately results in nothing happening*/
	
	/*User types scream*/
		/*A guard has been alerted*/
		
		/*The user types hide*/
			/*The guard has arrived and does not see you*/
			/*The user types use fur sharpener*/
			/*The guard is down, his keys are in sight*/
			/*The player types steal keys*/
				/*You now have the keys to the cell door*/
				/*Player types Exit*/
					/*Room_AddRoomExit(room, "out", 1);*/
					
	
	
	
	
	
	
	
	
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	/*Room_AddRoomExit(room, "out", 1);*/
	Room_AddRoomExit(room, "test", 5);
	/* TODO BASIC: Add room exit shortcut for "n" */
	
	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */

	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 */
Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	/* TODO BASIC: Add room exit shortcut for "s" */

	/* TODO REQUIRED: Add a brick to the list of items in the room */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 2 */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}

Room* Room3_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room4_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
 
	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room5_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("You have encounted the border of Beargaria. Before you is a small booth with nobawk attending to it. Wait, nevermind; there is a border agent present, but she is much smaller than your bearish brethren, leaving her almost unnoticed. How sad.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
    /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Mud_Build());
	ItemList_AddItem(Room_GetItemList(room), ProleHen_Build());

	/* Return the new room */
	return room;
}

Room* Room6_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("If Yuval were less lazy, there would be content here. Dang.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */	

										 /* Items
										 add items to the room */

	/* Return the new room */
	return room;
}

Room* Room7_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits */
	/*add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

/* TODO REQUIRED: Build room 8 */
Room* Room8_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 8 description:
	"This is room 8.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You enter the Garden. There is a gate to the north. Two Boarhound guards stand next to the gate. You need a weapon to get past them.");
	/* TODO REQUIRED: Add an Exit "west" to Room 6 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "west", 6);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Claw_Build());
	/* return the new room */
	return room;
}

Room* Room9_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

Room* Room10_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 10 description:
	"This is room 10.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You enter the Executive Bathroom. There is a vent at the top of the eastern wall.");
	/* TODO REQUIRED: Add an Exit "south" to Room 8 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	Room_AddRoomExit(room, "south", 8);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Screw_Build());
	/* return the new room */
	return room;
}

Room* Room11_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

										 /* Items
										 add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}

/* TODO ADVANCED: Build room 3 */
/* TODO ADVANCED: Build room 4 */


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 12;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());
	WorldData_SetRoom(worldData, 8, Room8_Build());
	WorldData_SetRoom(worldData, 10, Room10_Build());

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}
/******************************************************************************
filename    BookOfLoreFunctions.c
author      Yuval Talby
3/22/2019
******************************************************************************/

#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

/* Build a "brick" object */
Item* BookOfLore_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("book of linguistics", "a book aimed at teaching conversational chickish", true, NULL, NULL, NULL, NULL);
}
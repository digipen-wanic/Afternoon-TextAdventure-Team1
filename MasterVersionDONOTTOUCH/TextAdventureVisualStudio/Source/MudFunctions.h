/******************************************************************************
filename    MudFunctions.h
author      Yuval Talby
3/22/2019
******************************************************************************/

#pragma once

typedef struct Item Item;
typedef struct GameState GameState;


/*look at the mud*/
void Mud_Look(int context, GameState* gameState, WorldData* worldData);

/* Build a "mud" object */
Item* Mud_Build();
#pragma once

typedef struct Item Item;
typedef struct GameState GameState;


/*look at the mud*/
void Mud_Look(int context, GameState* gameState, WorldData* worldData);

/* Build a "mud" object */
Item* Mud_Build();
/******************************************************************************
filename    ScreamCommandHandler.h
author      Jordan Driscoll
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "look" user command, which outputs
a description of an item or the current room.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "leave" command, which outputs a description of an item or the current room */
void HandleDanceCommand(CommandData* command, GameState *gameState, WorldData *worldData); 

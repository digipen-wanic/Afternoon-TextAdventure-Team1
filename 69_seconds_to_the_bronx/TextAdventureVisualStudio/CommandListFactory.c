/******************************************************************************
filename    CommandFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the CommandList factory, creating the commands used 
in this game.

******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandListFactory.h" /* Function declarations */
#include "CommandList.h" /* CommandList and CommandList_Add */
#include "CommandHandlerFunctions.h" /* all Handle___Command functions */


/* Create the command list with all commands used in this game.*/
CommandList* CreateCommandList()
{
	/* The command list to be returned, starting empty */
	CommandList* commandList = NULL; 
	CommandList** cmdListPtr = &commandList;
	
	/*
	* NOTES: - Add the commands in the reverse of the order they'll be used, to reduce searching.
	*		 - Short alias commands do not show up in help.
	*/

	/* EXAMPLE: This is how you create the "help" command
				and add it to the list of commands for the game
	   NOTICE:  It uses a function called HandleHelpCommand, you can find
				additional command handler functions by looking here: CommandHandlerFunctions.h */

	/*Yuval connect*/
	CommandList_Add(cmdListPtr, "help", HandleHelpCommand, true);
	/* TODO BASIC: add support for a short alias "h" */

	/* TODO REQUIRED: create the "quit" command */
	CommandList_Add(cmdListPtr, "quit", HandleQuitCommand, true);
	/* TODO BASIC: add a short alias "q" */

	/* TODO REQUIRED: create the "drop" command */
	CommandList_Add(cmdListPtr, "drop", HandleDropCommand, true);
	/* TODO BASIC: add a short alias "d" */

	/* TODO REQUIRED: create the "take" command */
	CommandList_Add(cmdListPtr, "take", HandleTakeCommand, true);
	/* TODO BASIC: add a short alias "t" */

	/* TODO REQUIRED: create the "use" command */
	CommandList_Add(cmdListPtr, "use", HandleUseCommand, true);
	/* TODO BASIC: add a short alias "u" */

	/* TODO REQUIRED: create the "look" command */
	CommandList_Add(cmdListPtr, "look", HandleLookCommand, true);
	/* TODO BASIC: add a short alias "l" */

	/* TODO REQUIRED: create the "inventory" command */
	CommandList_Add(cmdListPtr, "inventory", HandleInventoryCommand, true);
	/* TODO BASIC: add a short alias "i" */

	/* TODO REQUIRED: create the "go" command */
	CommandList_Add(cmdListPtr, "go", HandleGoCommand, true);
	/* TODO BASIC: add a short alias "g" */

	/* TODO ADVANCED: create aditional commands
	this should require the creation of additional .c files to implement the command functions */

	/* return the newly created command list */
	return commandList;
}
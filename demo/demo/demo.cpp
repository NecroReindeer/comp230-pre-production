// demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "demo.h"
#include "InitialisationError.h"


int main(int argc, char* args[])
{
	// Set up random seed
	srand(static_cast<unsigned int>(time(nullptr)));

  try
  {
    // Create instance of game
    Game game;
    game.run();
  }
  catch (InitialisationError &err)
  {
    MessageBoxA(NULL, err.what(), "Initialisation error", MB_OK | MB_ICONERROR);
    return 1;
  }
	
	return 0;
}

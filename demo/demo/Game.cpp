#include "stdafx.h"
#include "Game.h"
#include "InitialisationError.h"

// Instance of game for singleton design pattern
Game* Game::instance = nullptr;

Game* Game::getInstance()
{
  if (!instance)
  {
    instance = new Game();
  }

  return instance;
}

Game::Game()
{
  instance = this;
  initialiseSDL();
  initialiseOpenGL();
  initialiseGlew();
}

Game::~Game()
{
  //Destroy window	
  SDL_DestroyWindow(window);

  //Delete context
  SDL_GL_DeleteContext(context);

  //Quit SDL subsystems
  SDL_Quit();
}


void Game::initialiseSDL()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw InitialisationError("SDL_Init failed", SDL_GetError());
  }

  //Create window
  window = SDL_CreateWindow("COMP230 Tech Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (!window)
  {
    throw InitialisationError("SDL_CreateWindow failed", SDL_GetError());
  }

  //Create OpenGL context
  context = SDL_GL_CreateContext(window);
  if (!context)
  {
    throw InitialisationError("OpenGL context could not be created", SDL_GetError());
  }

  //Use Vsync
  if (SDL_GL_SetSwapInterval(1) < 0)
  {
    throw InitialisationError("Unable to set VSync", SDL_GetError());
  }
}


void Game::initialiseOpenGL()
{
  glClearColor(0.4f, 0.0f, 0.4f, 0.0f);
  // Enable depth test
  glEnable(GL_DEPTH_TEST);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS);
}


void Game::initialiseGlew()
{
  glewExperimental = GL_TRUE;
  GLenum glewError = glewInit();
  if (glewError != GLEW_OK)
  {
    printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
  }
}


void Game::run()
{
  running = true;

  //Initialise objects always present in the game from the start here
   BranchManager behviourTree(&falcon);
   falconBehaviour = behviourTree;


  // Main loop
  while (running)
  {
    handleEvents();
    update();
    render();
  }
}


void Game::update()
{
  //Call to updates for objects in the game
	falconBehaviour.update();
}


void Game::handleEvents()
{
  // Handle events such as key presses
  SDL_Event ev;
  if (SDL_PollEvent(&ev))
  {
    switch (ev.type)
    {
      // Close the game when user quits
      case SDL_QUIT:
        running = false;
        break;

      default:
        break;
    }
  }
  const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
  inputHandler.handleKeyBoardInput(keyboardState);
}


void Game::render()
{
  //Clear color buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Update screen
  SDL_GL_SwapWindow(window);
}
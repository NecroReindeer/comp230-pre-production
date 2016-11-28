#pragma once
#include "Falcon.h"
#include"BranchManager.h"
#include"PlayerInput.h"
#include"Shader.h"
#include"Floor.h"
#include"Mesh.h"

//! Main class that runs the game
class Game
{
public: 
  static Game* getInstance();

  // TODO: Change to get players screen res
  //! Window width
  static const int WINDOW_WIDTH = 640;
  //! Window height
  static const int WINDOW_HEIGHT = 480;

  void run();

  Falcon falcon;
  BranchManager falconBehaviour;
  PlayerInput inputHandler;
  Shader shaders;

private:
   //! Constructor
  Game();
  //! Destructor
  ~Game();
  static Game* instance;

  SDL_Window* window;
  SDL_GLContext glContext;

  bool running;

  //! Intialises SDL
  void initialiseSDL();
  //! Intialises OpenGL
  void initialiseOpenGL();
  //! Intialises GLew
  void initialiseGlew();

  float mouseSensitivity = 0.01f, movementMultipler = 0.05f;
  float playerPitch = 0, playerYaw = 0;
  int mouseX, mouseY;
};


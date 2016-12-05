#pragma once
#include "Falcon.h"
#include"BranchManager.h"
#include"PlayerInput.h"
#include"Shader.h"
#include"Plane.h"
#include"Mesh.h"
#include"perlinNoise.h"

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
  //! Run function that contains game main loop
  void run();

  //! Instance of the companion falcon AI
  Falcon falcon;
  //! Branch manager that manages the companions behaviour
  BranchManager falconBehaviour;
  //! Handles players keyboard and mouse input
  PlayerInput inputHandler;
  //! Loads and compliles the shaders
  Shader shaders;

private:
   //! Constructor
  Game();
  //! Destructor
  ~Game();
  static Game* instance;

  //! Window where game will be rendered
  SDL_Window* window;
  SDL_GLContext glContext;

  //! Bool for whether game is running
  bool running;

  //! Intialises SDL
  void initialiseSDL();
  //! Intialises OpenGL
  void initialiseOpenGL();
  //! Intialises GLew
  void initialiseGlew();

  //! float for how fast the mouse moves the camera
  float mouseSensitivity = 0.01f;
  //! float for how fast the player can move
  float movementMultipler = 0.05f;
  //! float for camera rotation
  float playerPitch = 0, playerYaw = 0;
  //! Mouse x and y coordinates
  int mouseX, mouseY;
};


#pragma once 
#include"PlayerInput.h"
#include"Shader.h"
#include"Floor.h"
#include"Mesh.h"


class Game
{
public: 
  static Game* getInstance();

  static const int WINDOW_WIDTH = 640;
  static const int WINDOW_HEIGHT = 480;

  void run();

  Shader shaders;

private:
  Game();
  ~Game();
  static Game* instance;

  SDL_Window* window;
  SDL_GLContext glContext;

  bool running;

  void initialiseSDL();
  void initialiseOpenGL();
  void initialiseGlew();

  float mouseSensitivity = 0.01f;
  float movementMultipler = 0.05f;

  float playerPitch = 0;
  float playerYaw = 0;
  int mouseX, mouseY;
};


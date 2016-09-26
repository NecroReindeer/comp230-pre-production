#pragma once


class Game
{
public: 
  static Game* getInstance();

  static const int WINDOW_WIDTH = 640;
  static const int WINDOW_HEIGHT = 480;

  void run();

private:
  Game();
  ~Game();
  static Game* instance;

  SDL_Window* window;
  SDL_GLContext context;

  bool running;

  void initialiseSDL();
  void initialiseOpenGL();
  void initialiseGlew();

  void update();
  void handleEvents();
  void render();
};


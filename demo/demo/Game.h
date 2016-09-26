#pragma once


class Game
{
public:
	Game();
	~Game();

	static Game* instance;

	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;

	void run();

private:
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


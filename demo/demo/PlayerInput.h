#pragma once

//! The class the processes player input
class PlayerInput
{
public:
	PlayerInput();
	~PlayerInput();

	//! Possible character directions / valid play input
	enum class KeyboardInput { Up, Down, Left, Right, None };

	//! The direction the chatacter is currently moving in
	KeyboardInput currentDirection;

	//! Check the keyboard state to see if a valid key has been pressed
	void handleKeyBoardInput(const Uint8* keyboardState);

	//! Check the mouse state to see where the mosue is and if a button has been pressed
	void handleKeyMouseInput(const Uint8* keyboardState);

private:
	// Will be WASD/default movement
	SDL_Scancode DEFAULT_UP = SDL_SCANCODE_W;
	SDL_Scancode DEFAULT_DOWN = SDL_SCANCODE_S;
	SDL_Scancode DEFAULT_LEFT = SDL_SCANCODE_A;
	SDL_Scancode DEFAULT_RIGHT = SDL_SCANCODE_D;

	//Alternate movement keys will be customisable
	SDL_Scancode ALTERNATE_UP = SDL_SCANCODE_UP;
	SDL_Scancode ALTERNATE_DOWN = SDL_SCANCODE_DOWN;
	SDL_Scancode ALTERNATE_LEFT = SDL_SCANCODE_LEFT;
	SDL_Scancode ALTERNATE_RIGHT = SDL_SCANCODE_RIGHT;

};



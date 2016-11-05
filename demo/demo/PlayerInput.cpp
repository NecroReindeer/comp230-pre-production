#include "stdafx.h"
#include "PlayerInput.h"


PlayerInput::PlayerInput()
{
}


PlayerInput::~PlayerInput()
{
}

void PlayerInput::handleKeyBoardInput(const Uint8* keyboardState)
{
	if (keyboardState[DEFAULT_UP] || keyboardState[ALTERNATE_UP])
	{
		currentDirection = KeyboardDirections::Up;
	}
	else if (keyboardState[DEFAULT_DOWN] || keyboardState[ALTERNATE_DOWN])
	{
		currentDirection = KeyboardDirections::Down;
	}
	else if (keyboardState[DEFAULT_LEFT] || keyboardState[ALTERNATE_LEFT])
	{
		currentDirection = KeyboardDirections::Left;
	}
	else if (keyboardState[DEFAULT_RIGHT] || keyboardState[ALTERNATE_UP])
	{
		currentDirection = KeyboardDirections::Right;
	}
	// TODO: else if for falcon commands
	else
	{
		currentDirection = KeyboardDirections::None;
	}
}

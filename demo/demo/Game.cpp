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
  SDL_GL_DeleteContext(glContext);

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
  glContext = SDL_GL_CreateContext(window);
  if (!glContext)
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

  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  // loading shaders
  GLuint programID = shaders.loadShaders("vertex.glsl", "fragment.glsl");
  // setting up uniforms
  GLuint mvpLocation = glGetUniformLocation(programID, "mvp");
  GLuint lightDirectionLocation = glGetUniformLocation(programID, "lightDirection");
  GLuint cameraSpaceLocation = glGetUniformLocation(programID, "cameraSpace");

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_CULL_FACE);

  glm::vec4 playerPosition(0, 0, 5, 1);

  SDL_SetRelativeMouseMode(SDL_TRUE);
  SDL_GetRelativeMouseState(nullptr, nullptr);
  Uint32 lastFrameTime = SDL_GetTicks();

  Floor floor(-2, 10, "leaf.png");
  //Initialise objects always present in the game from the start here
   BranchManager behviourTree(&falcon);
   falconBehaviour = behviourTree;
   
   // For testing
   Mesh falconAliveMesh;
   falconAliveMesh.addSphere(1, 16, glm::vec3(1,1,1));
   falconAliveMesh.createBuffers();

   Mesh falconDeadMesh;
   falconDeadMesh.addSphere(1, 16, glm::vec3(0, 0, 1));
   falconDeadMesh.createBuffers();


  // Main loop
  while (running)
  {
	  SDL_Event ev;
	  if (SDL_PollEvent(&ev))
	  {
		  switch (ev.type)
		  {
			  // Close the game when user quits
		  case SDL_QUIT:
			  running = false;
			  break;

		  case SDLK_ESCAPE:
			  running = false;
			  break;
		  default:
			  break;
		  }
	  }
	  const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	  if (keyboardState[SDL_SCANCODE_ESCAPE])
		  running = false;
	   
	  falcon.update();
	  falconBehaviour.update();
	  falcon.setHealth(falcon.getHealth() - 1);  // for testing branch switching

	  SDL_GetRelativeMouseState(&mouseX, &mouseY);
	  playerYaw -= mouseX * mouseSensitivity;
	  playerPitch -= mouseY * mouseSensitivity;
	  const float maxPitch = glm::radians(89.0f);
	  if (playerPitch > maxPitch)
		  playerPitch = maxPitch;
	  if (playerPitch < -maxPitch)
		  playerPitch = -maxPitch;

	  glm::vec4 playerLook(0, 0, -1, 0);
	  glm::mat4 playerRotation;
	  playerRotation = glm::rotate(playerRotation, playerYaw, glm::vec3(0, 1, 0));
	  playerRotation = glm::rotate(playerRotation, playerPitch, glm::vec3(1, 0, 0));
	  playerLook = playerRotation * playerLook;

	  glm::vec4 playerForward = playerLook;

	  // TODO: Change to use PlayerInput class
	  if (keyboardState[SDL_SCANCODE_W])
	  {
		  playerPosition += playerForward * movementMultipler;
		  playerPosition.y = 0;
	  }
	  if (keyboardState[SDL_SCANCODE_S])
	  {
		  playerPosition -= playerForward * movementMultipler;
		  playerPosition.y = 0;
	  }

	  glm::vec4 playerRight(0, 0, -1, 0);
	  glm::mat4 playerRightRotation;
	  playerRightRotation = glm::rotate(playerRightRotation, playerYaw - glm::radians(90.0f), glm::vec3(0, 1, 0));
	  playerRight = playerRightRotation * playerRight;

	  if (keyboardState[SDL_SCANCODE_A])
	  {
		  playerPosition -= playerRight * movementMultipler;
		  playerPosition.y = 0;
	  }
	  if (keyboardState[SDL_SCANCODE_D])
	  {
		  playerPosition += playerRight * movementMultipler;
		  playerPosition.y = 0;
	  }

	  // Calculate delta time
	  Uint32 currentTime = SDL_GetTicks();
	  float deltaTime = (currentTime - lastFrameTime) / 1000.0f;
	  lastFrameTime = currentTime;

	  glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
	  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	  glUseProgram(programID);

	  glm::mat4 view = glm::lookAt(glm::vec3(playerPosition), glm::vec3(playerPosition + playerLook), glm::vec3(0, 1, 0));
	  glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

	  glm::mat4 transform;
	  glUniform3f(lightDirectionLocation, 1, 1, 1);
	  glUniform3f(cameraSpaceLocation, playerPosition.x, playerPosition.y, playerPosition.z);

	  glm::mat4 mvp;
	  glm::vec3 falconPos(falcon.getX(), falcon.getY(), falcon.getZ());
	  //falcon.setY(falcon.getY() + 1);
	  transform = glm::mat4();
	  transform = glm::translate(transform, falconPos);
	  mvp = projection * view * transform;
	  glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));
	  
	  if (falcon.getHealth() > 50)
		falconAliveMesh.draw();
	  else 
		 falconDeadMesh.draw();
	  
	  // Render floor
	  transform = glm::mat4();
	  mvp = projection * view * transform;
	  glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));
	  floor.texture.bindTexture();
	  floor.mesh.draw();
	  

	  SDL_GL_SwapWindow(window);
  
  }
}

#pragma once
#include "stdafx.h"
#include "08_Physics.h"
#include "Mesh.h"
#include "Ball.h"
#include "perlinNoise.h"


//Brings up error message if issues appear
void showErrorMessage(const char* message, const char* title)
{
	MessageBoxA(nullptr, message, title, MB_OK | MB_ICONERROR);
}

//compiles shaders 
bool compileShader(GLuint shaderId, const std::string& shaderFileName)
{
	std::string shaderSource;
	std::ifstream sourceStream(shaderFileName, std::ios::in);
	if (sourceStream.is_open()) //if files is open get shader information
	{
		std::stringstream buffer;
		buffer << sourceStream.rdbuf();
		shaderSource = buffer.str();
		sourceStream.close();
	}
	else
	{
		showErrorMessage(shaderFileName.c_str(), "File not found");
		return false;
	}

	const char* sourcePointer = shaderSource.c_str();
	glShaderSource(shaderId, 1, &sourcePointer, NULL);
	glCompileShader(shaderId);

	GLint result = GL_FALSE;
	int infoLogLength = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 1)
	{
		std::vector<char> errorMessage(infoLogLength + 1);
		glGetShaderInfoLog(shaderId, infoLogLength, NULL, errorMessage.data());
		showErrorMessage(errorMessage.data(), shaderFileName.c_str());
	}

	return (result != GL_FALSE);
}

//loading the shaders
GLuint loadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path) {
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	compileShader(vertexShaderId, vertex_file_path);

	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	compileShader(fragmentShaderId, fragment_file_path);

	GLuint programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);

	GLint result = GL_FALSE;
	int infoLogLength = 0;
	glGetProgramiv(programId, GL_LINK_STATUS, &result);
	glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 1) {
		std::vector<char> errorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programId, infoLogLength, NULL, errorMessage.data());
		showErrorMessage(errorMessage.data(), "glLinkProgram error");
	}

	glDetachShader(programId, vertexShaderId);
	glDetachShader(programId, fragmentShaderId);

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	return programId;
}

/*A new terrain is made by going through a grid and assigning values based on what is randomly generated through perlin noise. It assigns the squares
different Y values*/
Mesh* terrain()
{
	Mesh* myTerrain = new Mesh;
	perlinNoise pn;
	for (int x = 0; x < 30; x++)
	{
		for (int z = 0; z < 30; z++) //creating a grid
		{
			double land = pn.noise(x / 5.0, z / 5.0, 0) * 5; //perlin result equals the x,y coordinate
			myTerrain->addSquare(glm::vec3(x, land, z), glm::vec3(x + 1, land, z), glm::vec3(x + 1,land, z+1), glm::vec3(x, land, z+1), glm::vec3(1, 0, 0), 0, 0, 0, 0);
		}
	}

	myTerrain->createBuffers();
	return myTerrain;
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		showErrorMessage(SDL_GetError(), "SDL_Init failed");
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_Window* window = SDL_CreateWindow("My first OpenGL program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		showErrorMessage(SDL_GetError(), "SDL_CreateWindow failed");
		return 1;
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if (glContext == nullptr)
	{
		showErrorMessage(SDL_GetError(), "SDL_GL_CreateContext failed");
		return 1;
	}

	if (glewInit() != GLEW_OK)
	{
		showErrorMessage("glewInit failed", ":(");
		return 1;
	}

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint programID = loadShaders("vertex.glsl", "fragment.glsl");

	GLuint mvpLocation = glGetUniformLocation(programID, "mvp");

	GLuint lightDirectionLocation = glGetUniformLocation(programID, "lightDirection");

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//glEnable(GL_CULL_FACE);

	glm::vec4 playerPosition(0, 0, 5, 1);
	float playerPitch = 0;
	float playerYaw = 0;

	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_GetRelativeMouseState(nullptr, nullptr);

	Uint32 lastFrameTime = SDL_GetTicks();

	Mesh* landMass = terrain();

	bool running = true;
	while (running)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch (ev.type)
			{
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				switch (ev.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}
		}

		int mouseX, mouseY;
		SDL_GetRelativeMouseState(&mouseX, &mouseY);
		playerYaw -= mouseX * 0.005f;
		playerPitch -= mouseY * 0.005f;
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


		//getting key states to determin where player is moving.
		const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
		if (keyboardState[SDL_SCANCODE_W])
		{
			playerPosition += playerForward * 0.001f;
		}
		if (keyboardState[SDL_SCANCODE_S])
		{
			playerPosition -= playerForward * 0.001f;
		}

		glm::vec4 playerRight(0, 0, -1, 0);
		glm::mat4 playerRightRotation;
		playerRightRotation = glm::rotate(playerRightRotation, playerYaw - glm::radians(90.0f), glm::vec3(0, 1, 0));
		playerRight = playerRightRotation * playerRight;

		if (keyboardState[SDL_SCANCODE_A])
		{
			playerPosition -= playerRight * 0.001f;
		}
		if (keyboardState[SDL_SCANCODE_D])
		{
			playerPosition += playerRight * 0.001f;
		}

		// Calculate delta time
		Uint32 currentTime = SDL_GetTicks();
		float deltaTime = (currentTime - lastFrameTime) / 1000.0f;
		lastFrameTime = currentTime;

		glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

		glm::mat4 view = glm::lookAt(glm::vec3(playerPosition), glm::vec3(playerPosition + playerLook), glm::vec3(0, 1, 0));
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

		glm::mat4 transform;


		glUniform3f(lightDirectionLocation, 1, 1, 1);

		glm::mat4 mvp = projection * view * transform;
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		transform = glm::mat4(); // identity
		mvp = projection * view * transform;
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		landMass->draw(); //draws the terrain

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}

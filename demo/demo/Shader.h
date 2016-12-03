#pragma once
#include"ErrorMessage.h"

//! Class for shaders.
/*!
This is a class for loading and compiling shaders
*/
class Shader
{
public:
	//! Constructor
	Shader();
	//! Destructor
	~Shader();

	//! Error system to create error windows
	ErrorMessage errorSystem;
	//! Loads shaders
	/*!
		returns a GLuint for the shader
	*/
	GLuint loadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path);
	//! Complies shaders
	/*!
		returns bool depending on whether compliation was successful
	*/
	bool compileShader(GLuint shaderId, const std::string& shaderFileName);
};


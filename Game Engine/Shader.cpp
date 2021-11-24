#include "Shader.h"

#include <iostream>
#include <fstream>
#include <sstream>

/* static function to read a file to a string*/
static std::string readFile(const std::string filepath) {
	std::ifstream t(filepath);
	std::stringstream buffer;
	buffer << t.rdbuf();

	return buffer.str();
}

/* Creates an OpenGL shader program */
GLuint CreateShaderProgram(const std::string & vertexFilepath, const std::string & fragmentFilepath)
{
	GLuint program = glCreateProgram();

	//get shader source codes
	std::string vertexSrc = readFile(vertexFilepath);
	std::string fragmentSrc = readFile(fragmentFilepath);

	//compile shaders
	GLuint vertexShader = CompileShader(vertexSrc, GL_VERTEX_SHADER);
	GLuint fragmentShader = CompileShader(fragmentSrc, GL_FRAGMENT_SHADER);

	//attach shaders to program
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);
	glValidateProgram(program);

	//clean up shaders (they are now stored in the program)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return program;
}

GLuint CompileShader(const std::string& source, GLuint type) {
	GLuint shader = glCreateShader(type);
	//convert source to C string
	const char* src = source.c_str();

	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);

	//check for errors
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

		char* message = (char*)alloca(length);
		glGetShaderInfoLog(shader, length, &length, message);

		std::cout << "Failed to compile shader!" << std::endl;
		std::cout << message << std::endl;

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}

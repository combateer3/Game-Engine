#pragma once

#include <string>
#include <GL/glew.h>

GLuint CreateShaderProgram(const std::string& vertexFilepath, const std::string& fragmentFilepath);
GLuint CompileShader(const std::string& source, GLuint type);

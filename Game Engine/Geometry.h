#pragma once

#include <GL/glew.h>

/* Defintion for an object that holds a generic geometry
typedef struct _corbat_geometry {
	GLfloat* positions;
	unsigned int positions_len;

	GLuint* indices;
	unsigned int indices_len;

	//shader program to use for this geometry
	GLuint program;
} geometry; */

/* class definition for a geometry object */
class Geometry {
private:
	GLfloat* positions;
	unsigned int positions_len;

	GLuint* indices;
	unsigned int indices_len;

	GLuint program;

	//opengl variables
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

public:
	Geometry(GLuint program);

	void SetPositions(GLfloat* positions, unsigned int count);
	void SetIndices(GLuint* indices, unsigned int count);

	void BindVAO();
	
	inline GLuint PositionsCount() const { return positions_len; }
	inline GLuint IndicesCount() const { return indices_len; }
};

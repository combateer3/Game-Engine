#include "Geometry.h"

Geometry::Geometry(GLuint program)
	: program(program) {
	//create a vao for the geometry
	glGenBuffers(1, &vao);
}

/* set positions with given number of positions */
void Geometry::SetPositions(GLfloat* positions, unsigned int count) {
	positions_len = count;
	//create a vertex buffer for the positions
	glGenBuffers(1, &vbo);

	//get previously bound vao and store it
	GLint prevVAO;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &prevVAO);
	//bind and set data
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * count * 3, positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(GLfloat) * 3, nullptr);

	//rebind previous vertex array
	glBindVertexArray(prevVAO);
}

void Geometry::SetIndices(GLuint* indices, unsigned int count) {
	indices_len = count;
	//create element buffer
	glGenBuffers(1, &ibo);

	//get current vao to bind it later
	GLint prevVAO;
	glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &prevVAO);

	//bind and set data
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * count, indices, GL_STATIC_DRAW);

	//rebind previous vao
	glBindVertexArray(prevVAO);
}

void Geometry::BindVAO() {
	glBindVertexArray(vao);
}
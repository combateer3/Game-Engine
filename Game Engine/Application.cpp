#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "corbat_lib.h"

//singleton renderer
Renderer renderer;

float positions[] = {
		0, 0.5, 0,
		0.5, 0, 0,
		0.5, 0.5, 0
};

unsigned int indices[] = {
	0, 1, 2
};

void createTriangle() {
	float positions[] = {
		0, 0.5, 0,
		0.5, 0, 0,
		0.5, 0.5, 0
	};

	unsigned int indices[] = {
		0, 1, 2
	};

	unsigned int vao, vbo, ibo;
	glGenBuffers(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 3, nullptr);

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	//initialize GLEW
	glewInit();

	//createTriangle();

	//create shader
	GLuint program = CreateShaderProgram("vertexShader.vert", "fragmentShader.frag");
	glUseProgram(program);

	Geometry geom(program);
	geom.SetPositions(positions, 3);
	geom.SetIndices(indices, 3);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
		renderer.Draw(&geom);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
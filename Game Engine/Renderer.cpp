#include "Renderer.h"

void Renderer::Draw(Geometry* geom) {
	//bind the vao of the given geometry
	geom->BindVAO();

	//if the geometry has indices, use them, otherwise draw from arrays
	if (geom->IndicesCount() > 0) {
		glDrawElements(GL_TRIANGLES, geom->IndicesCount(), GL_UNSIGNED_INT, nullptr);
	}
	else {
		glDrawArrays(GL_TRIANGLES, 0, geom->PositionsCount());
	}
}
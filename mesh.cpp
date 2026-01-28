#include "mesh.h"

std::vector<Vector3> Mesh::getVertices()
{
	return vertices;
}

std::vector<uint16_t> Mesh::getIndices()
{
	return indices;
}

std::vector<Vector2> Mesh::getUVs()
{
	return uvs;
}

bool Mesh::isDirty(){
	return _isDirty;
}
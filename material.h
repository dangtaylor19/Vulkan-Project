#pragma once
#include <string>

using namespace std;

class Material {
public:
	Material() {
		vertexShaderPath = "shaders/vert.spv";
		fragmentShaderPath = "shaders/frag.spv";
	}
private:
	std::string vertexShaderPath;
	std::string fragmentShaderPath;
};
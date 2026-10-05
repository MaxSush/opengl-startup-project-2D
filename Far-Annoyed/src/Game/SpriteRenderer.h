#pragma once
#include "Utility/SHADER.h"
#include "Utility/VAO.h"
#include "Utility/TEXTURE.h"
#include "Utility/EBO.h"

class SpriteRenderer
{
public:
	SpriteRenderer(const Shader& shader);
	~SpriteRenderer();
	void DrawCube(glm::vec2 pos, glm::vec2 size, glm::vec4 color = { 1.0f,1.0f,1.0f,1.0f });
	void DrawSprite(const Texture& texture, glm::vec2 pos, glm::vec2 size, glm::vec4 color = { 1.0f,1.0f,1.0f,1.0f });
private:
	const Shader& shader;

	VAO vao;
	VBO vbo;
	EBO ebo;

	void Init();
};
#pragma once
#include <glad/glad.h>
#include "VBO.h"

class VAO
{
public:
	VAO();
	~VAO() noexcept;

	void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset);
	
	VAO(const VAO&) = delete;
	VAO& operator=(const VAO&) = delete;

	VAO(VAO&& other) noexcept;
	VAO& operator=(VAO&& other) noexcept;

	void Bind() const;
	void Unbind();

	GLuint GetID() const noexcept { return ID; }
private:
	GLuint ID = 0;
};


#pragma once
#include <glad/glad.h>

class VBO
{
public:
	VBO() noexcept = default;
	VBO(const GLfloat* vertices, GLsizeiptr size);
	~VBO() noexcept;

	VBO(const VBO&) = delete;
	VBO& operator=(const VBO&) = delete;

	VBO(VBO&& other) noexcept;
	VBO& operator=(VBO&& other) noexcept;

	void Bind() const;
	void Unbind() const;
	
	GLuint GetID() const noexcept { return ID; }

private:
	GLuint ID = 0;
};


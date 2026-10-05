#pragma once
#include <glad/glad.h>

class EBO
{
public:
	EBO() noexcept = default;
	EBO(const GLuint* indices, GLsizeiptr size);
	~EBO() noexcept;

	EBO(const EBO&) = delete;
	EBO& operator=(const EBO&& other) = delete;

	EBO(EBO&& other) noexcept;
	EBO& operator=(EBO&& other) noexcept;

	void Bind() const;
	void Unbind();

	GLuint GetID() const noexcept { return ID; }

private:
	GLuint ID = 0;
};


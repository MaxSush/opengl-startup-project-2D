#include "EBO.h"

EBO::EBO(const GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

EBO::~EBO() noexcept
{
	if (ID != 0)
	{
		glDeleteBuffers(1, &ID);
	}
	ID = 0;
}

EBO::EBO(EBO&& other) noexcept
	:ID(other.ID)
{
	other.ID = 0;
}

EBO& EBO::operator=(EBO&& other) noexcept
{
	if (this != &other)
	{
		if (ID != 0)
		{
			glDeleteBuffers(1, &ID);
		}
		ID = other.ID;
		other.ID = 0;
	}
	return *this;
}

void EBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#include "VBO.h"

VBO::VBO(const GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VBO::~VBO() noexcept
{
	if (ID != 0)
	{
		glDeleteBuffers(1, &ID);
	}
	ID = 0;
}

VBO::VBO(VBO&& other) noexcept
	: ID(other.ID)
{
	other.ID = 0;
}

VBO& VBO::operator=(VBO&& other) noexcept
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

void VBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

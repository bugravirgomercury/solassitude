#include <solassitude/gl_vertex_array.h>

// Include GLEW. Include it before GL headers, due to their
// stateful nature.
#include <GL/glew.h>

// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define __GL_CHECK_ERROR GLenum err{ ::glGetError() }; if (err != GL_NO_ERROR) { throw solassitude::gl::error{ err }; }

solassitude::gl::vertex_arrays::vertex_arrays(int n) {
	m_vaos.resize(n);
	glGenVertexArrays(n, m_vaos.data());
	
	__GL_CHECK_ERROR
}

solassitude::gl::vertex_arrays::~vertex_arrays() {
	glDeleteVertexArrays(m_vaos.size(), m_vaos.data());
	
	// No need to check for error, n will be always greater than 0.
}

solassitude::gl::vertex_array &solassitude::gl::vertex_array::bind(void) {
	glBindVertexArray(id());
	
	__GL_CHECK_ERROR
	
	return *this;
}
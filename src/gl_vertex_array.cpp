#include <solassitude/gl_vertex_array.h>

// Include GLEW. Include it before GL headers, due to their
// stateful nature.
#include <GL/glew.h>

// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define __GL_CHECK_ERROR GLenum err{ ::glGetError() }; if (err != GL_NO_ERROR) { throw solassitude::gl::error{ err }; }

#include <stdexcept> // std::logic_error

static inline GLuint _solassitude_new_vertex_array() {
	GLuint object_id;
	::glGenVertexArrays(1, &object_id);
	__GL_CHECK_ERROR
	return object_id;
}

solassitude::gl::vertex_array::vertex_array() : vertex_array{ _solassitude_new_vertex_array() } 
{
}

void solassitude::gl::vertex_array::on_destruct(void) {
	// Called by d'tor - no throwing exceptions, otherwise std::terminate is called
	// This method won't be called if c'tor threw exception, as that means the object
	// is NOT constructed, no d'tor will be called. Object ID is guaranteed to be valid.
	GLuint object_id{ id() }; // don't use pointer to prvalue as an input argument for pointer parameter!
	::glDeleteVertexArrays(1, &object_id);
	__GL_CHECK_ERROR
}

void solassitude::gl::vertex_array::on_activate(void) {
	::glBindVertexArray(id());
	__GL_CHECK_ERROR
}

void solassitude::gl::vertex_array::on_copy(const solassitude::gl::vertex_array &copy, bool is_assign) {
	UNUSED_PARAMETER(copy);
	UNUSED_PARAMETER(is_assign);
	
	// TODO: How to clone a VAO? Help wanted.
	throw std::logic_error{ "VAO cloning not yet implemented" };
}

void solassitude::gl::vertex_array::on_move(solassitude::gl::vertex_array &&move, bool is_assign) {
	// Make use the VAO is detached
	::glBindVertexArray(0);
	
	if (is_assign)
		this->on_destruct(); // Move assignment, destroy current one
		
	// ID move is handled by the base class, and we have no more fields to copy.
	UNUSED_PARAMETER(move);
	UNUSED_PARAMETER(is_assign);
}


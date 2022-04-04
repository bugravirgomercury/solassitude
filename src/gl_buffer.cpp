#include <solassitude/gl_buffer.h>

// Include GLEW. Include it before GL headers, due to their
// stateful nature.
#include <GL/glew.h>

// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define __GL_CHECK_ERROR GLenum err{ ::glGetError() }; if (err != GL_NO_ERROR) { throw solassitude::gl::error{ err }; }

static constexpr GLenum _solassitude_to_gl(solassitude::gl::buffer_target target) {
	switch (target) {
		case solassitude::gl::buffer_target::array: return GL_ARRAY_BUFFER;
		case solassitude::gl::buffer_target::atomic_counter: return GL_ATOMIC_COUNTER_BUFFER;
		case solassitude::gl::buffer_target::copy_read: return GL_COPY_READ_BUFFER;
		case solassitude::gl::buffer_target::copy_write: return GL_COPY_WRITE_BUFFER;
		case solassitude::gl::buffer_target::dispatch_indirect: return GL_DISPATCH_INDIRECT_BUFFER;
		case solassitude::gl::buffer_target::draw_indirect: return GL_DRAW_INDIRECT_BUFFER;
		case solassitude::gl::buffer_target::element_array: return GL_ELEMENT_ARRAY_BUFFER;
		case solassitude::gl::buffer_target::pixel_pack: return GL_PIXEL_PACK_BUFFER;
		case solassitude::gl::buffer_target::pixel_unpack: return GL_PIXEL_UNPACK_BUFFER;
		case solassitude::gl::buffer_target::query: return GL_QUERY_BUFFER;
		case solassitude::gl::buffer_target::shader_storage: return GL_SHADER_STORAGE_BUFFER;
		case solassitude::gl::buffer_target::texture: return GL_TEXTURE_BUFFER;
		case solassitude::gl::buffer_target::transform_feedback: return GL_TRANSFORM_FEEDBACK_BUFFER;
		case solassitude::gl::buffer_target::uniform: return GL_UNIFORM_BUFFER;
		default: return -1;
	}
}

solassitude::gl::buffer &solassitude::gl::buffer::bind(solassitude::gl::buffer_target target) {
	m_target = target;
	::glBindBuffer(_solassitude_to_gl(m_target), m_id);
	__GL_CHECK_ERROR
	return *this;
}
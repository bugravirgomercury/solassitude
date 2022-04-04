#include <GL/glew.h>
#include <solassitude/gl_abstract.h>

using solassitude::gl::buffer_bits;

void solassitude::gl::clear(buffer_bits bitmask) {
    GLbitfield mask{ 0 };
    
    if (bitmask && buffer_bits::color)
        mask |= GL_COLOR_BUFFER_BIT;
    if (bitmask && buffer_bits::depth)
        mask |= GL_DEPTH_BUFFER_BIT;
    if (bitmask && buffer_bits::stencil)
        mask |= GL_STENCIL_BUFFER_BIT;
        
    ::glClear(mask);
}

std::string solassitude::gl::error::what_for_error_code(GLuint error_code) const noexcept {
    auto contents = reinterpret_cast<const char *>(::glewGetErrorString((GLenum) error_code));
    return std::string{ contents };
}

solassitude::gl::error::error() : solassitude::gl::error::error{ (unsigned int) ::glGetError() } { }
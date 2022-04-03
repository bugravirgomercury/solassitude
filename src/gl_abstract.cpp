#include <GL/glew.h>
#include <solassitude/gl_abstract.h>

using solassitude::gl::buffers;

void solassitude::gl::clear(buffers bitmask) {
    GLbitfield mask{ 0 };
    
    if (bitmask && buffers::color)
        mask |= GL_COLOR_BUFFER_BIT;
    if (bitmask && buffers::depth)
        mask |= GL_DEPTH_BUFFER_BIT;
    if (bitmask && buffers::stencil)
        mask |= GL_STENCIL_BUFFER_BIT;
        
    ::glClear(mask);
}
// Include GLEW. Include it before GL headers, due to their
// stateful nature.
#include <GL/glew.h>

#include <solassitude/glew_abstract.h>

#include <string> // std::string

void solassitude::glew::experimental(bool bExperimental) noexcept {
    glewExperimental = bExperimental ? GL_TRUE : GL_FALSE;
}

bool solassitude::glew::experimental(void) noexcept {
    return glewExperimental == GL_TRUE ? true : false;
}

void solassitude::glew::initialize(void) {
    auto err = glewInit();
    if (GLEW_OK != err) {
        throw solassitude::glew_error{ err };
    }
}

void solassitude::glew::terminate(void) {
    // TODO: Unload GLEW library here.
}

std::string solassitude::glew_error::what_for_error_code(solassitude::glew_error::error_code_t error_code) const noexcept {
    return std::string{ reinterpret_cast<const char *>(glewGetErrorString(static_cast<GLenum>(error_code))) };
}
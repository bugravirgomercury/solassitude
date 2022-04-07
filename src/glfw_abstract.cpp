// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <solassitude/glfw_abstract.h>

#include <string> // std::string
#include <cassert> // assert

static inline std::string _solassitude_glfw_init_error(int &err_code) noexcept {
    const char *glfw_description{ nullptr };
    int glfw_code{ ::glfwGetError(&glfw_description) };
    err_code = glfw_code;
    if (GLFW_NO_ERROR == glfw_code) {
        return std::string{ "" };
    } else {
        return std::string{ glfw_description };
    }
}

// m_error_code will be remodified by the mutable reference, the function is needed to properly
// handle default initialization of error class.

solassitude::glfw::error::error() : solassitude::glfw::error{ 0, _solassitude_glfw_init_error(m_error_code) } { }


void solassitude::glfw::glfw::initialize(void) {
    if (!glfwInit()) {
        throw solassitude::glfw::error{}; // Gets the error code and description by default c'tor.
    }
}

void solassitude::glfw::glfw::terminate(void) {
    glfwTerminate();
}

void solassitude::glfw::glfw::msaa_samples(unsigned int samples) {
    glfwWindowHint(GLFW_SAMPLES, (int) samples);
}

void solassitude::glfw::glfw::context_version(unsigned int major, unsigned int minor) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, (int) major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, (int) minor);
}

void solassitude::glfw::glfw::gl_forward_compatible(bool compatible) {
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, compatible ? GLFW_TRUE : GLFW_FALSE);
}

void solassitude::glfw::glfw::gl_profile(solassitude::glfw::opengl_profile profile) {
    int p = 0;
    
    switch (profile) {
        case solassitude::glfw::opengl_profile::core: 
            p = GLFW_OPENGL_CORE_PROFILE;
            break;
            
        // *** Add other opengl context profiles as needed. ***
            
        default:
            assert(0 && "Have received unhandled gl_profile");
            break;
    }
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, p);
}
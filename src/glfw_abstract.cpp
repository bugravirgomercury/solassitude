// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <solassitude/glfw_abstract.h>

#include <string> // std::string
#include <cassert> // assert

solassitude::glfw::error::error() : solassitude::glfw::error{ ::glfwGetError(NULL) } { }

void solassitude::glfw::glfw::initialize(void) {
    if (!glfwInit()) {
        throw solassitude::glfw::error{ glfwGetError(NULL) };
    }
}

void solassitude::glfw::glfw::terminate(void) {
    glfwTerminate();
}

std::string solassitude::glfw::error::what_for_error_code(solassitude::glfw::error::error_code_t error_code) const noexcept {
    char description[256];
    glfwGetErrorDescription(error_code, description, sizeof(description));
    return std::string{ description };
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
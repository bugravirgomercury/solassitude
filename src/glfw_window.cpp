#include <solassitude/glfw_window.h>

// Include GLFW.
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <cassert> // assert

#define __GLFW_WINDOW static_cast<GLFWwindow *>(m_window)

solassitude::glfw::window::window(int width, int height, const std::string &title)
	: m_window{ ::glfwCreateWindow(width, height, title.c_str(), NULL, NULL) } {
	if (!m_window) {
		throw solassitude::glfw::error{};
	}
}

solassitude::glfw::window::~window() {
	::glfwDestroyWindow(__GLFW_WINDOW);
}

void solassitude::glfw::window::make_context_current(void) {
	::glfwMakeContextCurrent(__GLFW_WINDOW);
}

void solassitude::glfw::window::input_mode(solassitude::glfw::cursor_modes cursor_mode) {
	int p = 0;
	
	switch (cursor_mode) {
		case solassitude::glfw::cursor_modes::disabled:
			p = GLFW_CURSOR_DISABLED;
			break;
		case solassitude::glfw::cursor_modes::hidden:
			p = GLFW_CURSOR_HIDDEN;
			break;
		case solassitude::glfw::cursor_modes::normal:
			p = GLFW_CURSOR_NORMAL;
			break;
		default:
			assert(0 && "Unknown cursor mode has been reached. This is a bug");
			break;
	}
	
	::glfwSetInputMode(__GLFW_WINDOW, GLFW_CURSOR, p);
}

void solassitude::glfw::window::swap_buffers(void) {
	::glfwSwapBuffers(__GLFW_WINDOW);
}

void solassitude::glfw::window::poll_events(void) {
	::glfwPollEvents();
}

void solassitude::glfw::window::input_mode(solassitude::glfw::input_modes input_mode, bool enabled) {
	int p = 0;
	
	switch (input_mode) {
		case solassitude::glfw::input_modes::sticky_keys:
			p = GLFW_STICKY_KEYS;
			break;
		case solassitude::glfw::input_modes::sticky_mouse_buttons:
			p = GLFW_STICKY_MOUSE_BUTTONS;
			break;
		case solassitude::glfw::input_modes::lock_key_mods:
			p = GLFW_LOCK_KEY_MODS;
			break;
		case solassitude::glfw::input_modes::raw_mouse_motion:
			p = GLFW_RAW_MOUSE_MOTION;
			break;
		default:
			assert(0 && "Unknown input mode. If you're trying to use GLFW_CURSOR, use cursor_modes overload");
			break;
	}
	
	::glfwSetInputMode(__GLFW_WINDOW, p, (enabled ? GLFW_TRUE : GLFW_FALSE));
}

solassitude::glfw::key_state solassitude::glfw::window::key(solassitude::glfw::keys key_code) {
	// The key code enum is exactly the same as the GLFW's.
	auto kr = ::glfwGetKey(__GLFW_WINDOW, static_cast<int>(key_code));
	if (kr == GLFW_PRESS)
		return solassitude::glfw::key_state::pressed;
	else if (kr == GLFW_RELEASE)
		return solassitude::glfw::key_state::released;
	else
		assert(0 && "Invalid key_state encountered. This is a bug");
}

bool solassitude::glfw::window::should_close(void) {
	return ::glfwWindowShouldClose(__GLFW_WINDOW) == GLFW_TRUE;
}
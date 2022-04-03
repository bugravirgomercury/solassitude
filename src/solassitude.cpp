#include <iostream>
#include <string_view>
#include <experimental/source_location>

#include <solassitude/glew_abstract.h>
#include <solassitude/glfw_abstract.h>
#include <solassitude/glfw_window.h>
#include <solassitude/gl_abstract.h>

void log(const std::string_view& message,
		 const std::experimental::source_location &location = 
		 	   std::experimental::source_location::current()) 
{
	std::clog 	<< "["
				<< location.file_name() << ":"
				<< location.line() << ":"
				<< location.column() << "] "
				<< location.function_name() << ": "
				<< message << '\n';
}

int main(int argc, char const *argv[])
{
	solassitude::glew::experimental(true); // needed for core profile
	solassitude::glfw::glfw glfw; // Initialize GLFW
	
	solassitude::glfw::glfw::msaa_samples(4);
	solassitude::glfw::glfw::context_version(3, 2);
	solassitude::glfw::glfw::gl_forward_compatible(true);
	solassitude::glfw::glfw::gl_profile(solassitude::glfw::opengl_profile::core);
	
	solassitude::glfw::window window{ 640, 480, "Solassitude" };
	window.make_context_current();
	
	solassitude::glew::experimental(true);
	solassitude::glew glew;
	
	window.input_mode(solassitude::glfw::input_modes::sticky_keys, true);
	
	do {
		// clear screen
		solassitude::gl::clear(solassitude::gl::buffers::color);
		
		// swap buffers
		window.swap_buffers();
		solassitude::glfw::window::poll_events();
		
	} while (window.key(solassitude::glfw::keys::escape) != solassitude::glfw::key_state::pressed
			 && window.should_close() == false);
	
	return 0;
}

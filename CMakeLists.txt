cmake_minimum_required(VERSION 3.0)

project(solassitude)

add_executable(solassitude 
			   src/glfw_window.cpp
			   src/glew_abstract.cpp
			   src/glfw_abstract.cpp
			   src/gl_abstract.cpp
			   src/solassitude.cpp)

set_target_properties(
	solassitude PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)


target_include_directories(solassitude PUBLIC include)

target_link_libraries(solassitude GLEW glfw3 dl pthread GL)

target_compile_options(solassitude PRIVATE -Wall -Wextra) 
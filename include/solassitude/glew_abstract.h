#pragma once

#include "library_scope_guard.h"
#include "library_error.h"
#include <string> // std::string

namespace solassitude {
	class glew;
	class glew_error;
	
	class glew : public library_scope_guard<glew> {
		friend class library_scope_guard<glew>;
		
	public:
		static bool experimental() noexcept;
		static void experimental(bool experimental) noexcept;
		
	private:
		void initialize(void);
		void terminate(void);
	};
	
	class glew_error : public library_error<glew_error> {
	public:
		std::string what_for_error_code(error_code_t error_code) const noexcept;
		explicit glew_error(error_code_t error_code) : library_error{ error_code } { }
		~glew_error() { }
	};
}

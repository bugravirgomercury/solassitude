#pragma once

#include <stdexcept> // std::runtime_error
#include <utility> // std::move

namespace solassitude {
	template <class derived_t>
	struct library_error_traits {
		using error_code_t = unsigned int;
	};
	
	template <class derived_t>
	class library_error : public std::runtime_error {
	protected:
		using error_code_t = typename library_error_traits<derived_t>::error_code_t;
	
		error_code_t m_error_code;
		
	public:
		constexpr error_code_t error_code(void) const noexcept {
			return m_error_code;
		}
	
		explicit library_error(error_code_t error_code)
			: std::runtime_error{ static_cast<derived_t &>(*this).what_for_error_code(error_code) }
			, m_error_code{ error_code }
		{
		}
		
		virtual ~library_error()
		{
		}
		
		library_error<derived_t> &operator =(const library_error<derived_t> &other) {
			if (&other != this) {
				std::runtime_error::operator=(other);
				m_error_code = other.m_error_code;
			}
			
			return *this;
		}
		
		library_error<derived_t> &operator =(library_error<derived_t> &&other) {
			if (&other != this) {
				std::runtime_error::operator=(std::move(other));
				m_error_code = std::move(other.m_error_code);
			}
			
			return *this;
		}
		
		explicit library_error(const library_error<derived_t> &other)
			: std::runtime_error{ other }
			, m_error_code{ other.m_error_code }
		{
		}
		
		explicit library_error(library_error<derived_t> &&other)
			: std::runtime_error{ std::move(other) }
			, m_error_code{ std::move(other.m_error_code) }
		{
		}
	};
}
#pragma once

namespace solassitude {
	template <class library_t>
	class library_scope_guard {
	public:
		explicit library_scope_guard() : m_engaged{ true } { static_cast<library_t &>(*this).initialize(); }
		~library_scope_guard() { if (m_engaged) { static_cast<library_t &>(*this).terminate(); } }
		
		library_scope_guard(const library_scope_guard<library_t> &) = delete;
		library_scope_guard(library_scope_guard<library_t> &&) = delete;
		library_scope_guard<library_t> &operator =(const library_scope_guard<library_t> &) = delete;
		library_scope_guard<library_t> &operator =(library_scope_guard<library_t> &&) = delete;
		
		void release(void) noexcept {
			m_engaged = false; // The library will no longer be released.
		}
		
	protected:
		void initialize(void) { }
		void terminate(void) { }
		
	private:
		bool m_engaged;	
	};
}
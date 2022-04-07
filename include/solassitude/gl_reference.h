#pragma once

#include "gl_abstract.h"
#include <utility>

namespace solassitude {
	namespace gl {
		template <class derived_t> class reference {
		public:
			explicit reference(unsigned int _id) : m_id{ _id } { }
			
			~reference() { static_cast<derived_t &>(*this).on_destruct(); }
			
			constexpr unsigned int id(void) const noexcept { return m_id; }
			
			constexpr void id(unsigned int id) noexcept { m_id = id; }
			
			explicit reference(const reference<derived_t> &copy) : m_id{ copy.m_id } { 
				static_cast<derived_t *>(this)->on_copy(static_cast<const derived_t &>(std::forward(copy)), false);
			}
			
			explicit reference(reference<derived_t> &&move) : m_id{ std::move(move.m_id) } {
				static_cast<derived_t *>(this)->on_move(static_cast<derived_t &&>(std::forward(move)), false);
			}
			
			reference<derived_t> &operator =(const reference<derived_t> &copy) {
				if (&copy != this) {
					m_id = copy.m_id;
					static_cast<derived_t &>(*this).on_copy(static_cast<const derived_t &>(std::forward(copy)), true);
				}
				return *this;
			}
			
			reference<derived_t> &operator =(reference<derived_t> &&move) {
				if (&move != this) {
					m_id = std::move(move.m_id);
					static_cast<derived_t &>(*this)->on_move(static_cast<derived_t &&>(std::forward(move)), true);
				}
				return *this;
			}
			
			void activate(void) { static_cast<derived_t &>(*this).on_activate(); }
			
		protected:
		
			void on_destruct(void) { }
			void on_copy(const derived_t &copy, bool is_assign) { }
			void on_move(derived_t &&move, bool is_assign) { }
			void on_activate(void) { }
			
		private:
			unsigned int m_id;
		};
	}
}
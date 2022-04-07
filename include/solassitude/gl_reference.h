#pragma once

#include "gl_abstract.h"
#include <utility>

#define UNUSED_PARAMETER(x) (void)(x)

namespace solassitude {
	namespace gl {
		template <class derived_t> class reference : public object {
		public:
			explicit reference(unsigned int _id) : object{ _id } { }
			
			~reference() { static_cast<derived_t &>(*this).on_destruct(); }
			
			explicit reference(const reference<derived_t> &copy) : object{ copy } { 
				static_cast<derived_t &>(*this).on_copy(static_cast<const derived_t &>(copy), false);
			}
			
			explicit reference(reference<derived_t> &&move) : object{ std::move(move) } {
				static_cast<derived_t &>(*this).on_move(static_cast<derived_t &&>(std::move(move)), false);
			}
			
			reference<derived_t> &operator =(const reference<derived_t> &copy) {
				if (&copy != this) {
					this->operator=(std::forward(copy)); // copy assign object id
					static_cast<derived_t &>(*this).on_copy(static_cast<const derived_t &>(std::forward(copy)), true);
				}
				return *this;
			}
			
			reference<derived_t> &operator =(reference<derived_t> &&move) {
				if (&move != this) {
					this->operator=(std::forward(move)); // move assign object id
					static_cast<derived_t &>(*this).on_move(static_cast<derived_t &&>(std::forward(move)), true);
				}
				return *this;
			}
			
			void activate(void) { static_cast<derived_t &>(*this).on_activate(); }
			
		protected:
		
			void on_destruct(void) { }
			void on_copy(const derived_t &copy, bool is_assign) { UNUSED_PARAMETER(copy); UNUSED_PARAMETER(is_assign); }
			void on_move(derived_t &&move, bool is_assign) { UNUSED_PARAMETER(move); UNUSED_PARAMETER(is_assign); }
			void on_activate(void) { }
		};
	}
}
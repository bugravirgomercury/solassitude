#pragma once

#include "gl_abstract.h"
#include "gl_reference.h"
//#include <vector>
#include <utility> // std::forward

namespace solassitude {
	namespace gl {
		class vertex_array;
		
		class vertex_array : 
			public reference<vertex_array> {
				
		public:
			explicit vertex_array(unsigned int id) : reference{ id } { }
			explicit vertex_array(); // generate one with a new id.
			~vertex_array() { } // destructor needs to be defined, compiler will implicitly call reference::~reference()
			explicit vertex_array(const vertex_array &copy) : reference{ copy } { } // c++ does not inherit constructors
			explicit vertex_array(vertex_array &&move) : reference{ std::move(move) } { }
			
		protected:
			// The base class will call on_* methods (CRTP/NVI pattern).
			
			void on_destruct(void); // called by the base destructor
			void on_activate(void); // called by base activate() method
			void on_copy(const vertex_array &copy, bool is_assign); // called by base copy c'tor and assignment operator
			void on_move(vertex_array &&move, bool is_assign); // called by base move c'tor and assignment operator
		};
	}
}
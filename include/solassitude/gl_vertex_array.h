#pragma once

#include "gl_abstract.h"
#include <vector>

namespace solassitude {
	namespace gl {
		class vertex_arrays;
		class vertex_array;
		/*
		class vertex_array {
		private:
			friend class vertex_arrays;
			explicit vertex_array(unsigned int vao) : m_vao{ vao } { }
			
		public:
			vertex_array &bind(void);
			
		private:
			unsigned int m_vao;	
		};*/
		
		class vertex_array : public object {
		private:
			friend class vertex_arrays;
			explicit vertex_array(unsigned int vao) : object{ vao } { }
		public:
			vertex_array &bind(void);
			~vertex_array() { }
		};
		
		class vertex_arrays {
		public:
			explicit vertex_arrays(int n = 1);
			~vertex_arrays();
			
			vertex_array operator[](int i) noexcept {
				return vertex_array{ m_vaos.at(i) }.bind();
			}
			
			unsigned int size() const noexcept {
				return m_vaos.size();
			}
			
		private:
			std::vector<unsigned int> m_vaos;
		};
	}
}
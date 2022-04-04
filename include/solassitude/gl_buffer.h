#pragma once

#include "gl_abstract.h"
#include <vector>

namespace solassitude {
	namespace gl {
		class buffers;
		class buffer;
		
		enum class buffer_target {
			array,
			atomic_counter,
			copy_read,
			copy_write,
			dispatch_indirect,
			draw_indirect,
			element_array,
			pixel_pack,
			pixel_unpack,
			query,
			shader_storage,
			texture,
			transform_feedback,
			uniform,
			none
		};
		
		class buffer {
		private:
			friend class buffers;
			explicit buffer(unsigned int id) : m_id{ id }, m_target{ buffer_target::none } { }
			
		public:
			buffer &bind(buffer_target target = buffer_target::array);
			
		private:
			unsigned int m_id;
			buffer_target m_target;
		};
		
		class buffers {
		public:
			explicit buffers(int n = 1);
			~buffers();
			
			buffer operator[](int i) noexcept {
				return buffer{ m_ids.at(i) };
			}
			
			unsigned int size(void) const noexcept {
				return m_ids.size();
			}
			
		private:
			std::vector<unsigned int> m_ids;
		};
	}
}
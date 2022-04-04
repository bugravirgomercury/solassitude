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
		
		class buffer_impl : public object {
		public:
			explicit buffer_impl(buffer_target target, unsigned int id) : object{ id }, m_target{ target } { }
			~buffer_impl() { }
			
			buffer_impl &bind(void);
			
			constexpr buffer_target target(void) const noexcept {
				return m_target;
			}
			
			void target(buffer_target new_target) noexcept {
				m_target = new_target;
			}
		private:
			buffer_target m_target;
		};
	}
}
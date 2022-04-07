#pragma once

#include "gl_abstract.h"
#include <vector>

namespace solassitude {
	namespace gl {
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
	}
}
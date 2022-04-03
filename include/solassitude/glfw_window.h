#pragma once

#include <solassitude/glfw_abstract.h>
#include <string>

namespace solassitude {
	namespace glfw {
		enum class cursor_modes {
			normal,
			hidden,
			disabled
		};
		
		enum class input_modes {
			sticky_keys,
			sticky_mouse_buttons,
			lock_key_mods,
			raw_mouse_motion
		};
		
		class window {
		public:
			explicit window(int width,
							int height,
							const std::string &title);
			
			~window();
			
			void make_context_current(void);
			void input_mode(cursor_modes cursor_mode);
			void input_mode(input_modes input_mode, bool enabled);
			void swap_buffers(void);
			
			key_state key(keys key_code);
			
			bool should_close(void);
			
			static void poll_events(void);
		private:
			void *m_window;
		};
	}
}
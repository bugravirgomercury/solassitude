#pragma once

#include "library_scope_guard.h"
#include "library_error.h"
#include <string> // std::string

namespace solassitude {
    namespace glfw {
        class error;
    }
    
    template <>
    struct library_error_traits<glfw::error> {
        using error_code_t = int;	
    };
    
    namespace glfw {
        enum class opengl_profile {
            core
        };
        
        class glfw : public library_scope_guard<glfw> {
            friend class library_scope_guard<glfw>;
            
        private:
            void initialize(void);
            void terminate(void);
            
        public:
            static void msaa_samples(unsigned int samples);
            static void context_version(unsigned int major, unsigned int minor);
            static void gl_forward_compatible(bool compatible);
            static void gl_profile(opengl_profile profile);
        };
        
        class error : public library_error<error> {
        public:
            /* 
            * TODO: While GLFW error handling does allow acquiring error code and its description,
            * 		 it does not have a function for acquiring description for a specific
            *		 error code. The library_error abstraction requires a way to get error message
            *		 for specific error code passed in the constructor, so this class is shelved
            *		 for now. Look for issue #2071 on GLFW GitHub repository.
            *		 (https://github.com/glfw/glfw/issues/2071)
            */
                
        
            std::string what_for_error_code(error_code_t error_code) const noexcept;
            
            explicit error(error_code_t error_code) : library_error{ error_code } { }
            explicit error();
            ~error() { }
        };
        
        enum class key_state {
            pressed,
            released
        };
        
        enum class keys {
            unknown = -1,
            
            space = 32,
            
            apostrophe = 39,
            
            comma = 44,
            minus,	period,		slash,
            zero,	one,		two,
            three,	four,		five,
            six,	seven,		eight,
            nine,
            
            semicolon = 59,
            
            equal = 61,
            
            a = 65,
            b,c,d,e,f,g,h,i,j,k,l,m,n,
            o,p,q,r,s,t,u,v,w,x,y,z,
            left_bracket,
            backslash,
            right_bracket,
            
            grave_accent = 96,
            
            world_1 = 161,
            world_2,
            
            escape = 256,
            enter, tab, backspace, insert, _delete,
            right, left, down, up, page_up, page_down,
            home, end, 
            
            caps_lock = 280, 
            scroll_lock, num_lock, print_screen,
            pause,
            
            f1 = 290, 
            f2, f3, f4, f5, f6,
            f7, f8, f9, f10, f11, f12, f13,
            f14, f15, f16, f17, f18, f19,
            f20, f21, f22, f23, f24, f25,
            
            kp_0 = 320, 
            kp_1, kp_2, kp_3, kp_4, kp_5, kp_6,
            kp_7, kp_8, kp_9, kp_decimal, kp_divide,
            kp_multiply, kp_substract, kp_add,
            kp_enter, kp_equal,
            
            left_shift = 340, left_control, left_alt,
            left_super, right_shift, right_control,
            right_alt, right_super, menu,
            
            last = menu
        };
    }
}
#pragma once

#include "library_error.h"

namespace solassitude {
    namespace gl {
        class error : public solassitude::library_error<error> {
        public:
            std::string what_for_error_code(error_code_t error_code) const noexcept;
            explicit error(error_code_t error_code) : library_error{ error_code } { }
            explicit error();
            ~error() { }
        };
        
        enum class buffer_bits {
            color 	= 0x01,
            depth 	= 0x02,
            stencil	= 0x04,
            none	= 0x00
        };
        
        constexpr buffer_bits operator|(const buffer_bits &a, const buffer_bits &b) noexcept {
            return static_cast<buffer_bits>(static_cast<int>(a) | static_cast<int>(b));
        }
        
        constexpr buffer_bits operator&(const buffer_bits &a, const buffer_bits &b) noexcept {
            return static_cast<buffer_bits>(static_cast<int>(a) & static_cast<int>(b));
        }
        
        constexpr bool operator&&(const buffer_bits &a, const buffer_bits &b) noexcept {
            return static_cast<int>(a & b) != 0;
        }
        
        void clear(buffer_bits bitmask);
    }
}
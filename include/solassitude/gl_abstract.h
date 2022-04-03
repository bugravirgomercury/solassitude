#pragma once

namespace solassitude {
    namespace gl {
        enum class buffers {
            color 	= 0x01,
            depth 	= 0x02,
            stencil	= 0x04,
            none	= 0x00
        };
        
        constexpr buffers operator|(const buffers &a, const buffers &b) noexcept {
            return static_cast<buffers>(static_cast<int>(a) | static_cast<int>(b));
        }
        
        constexpr buffers operator&(const buffers &a, const buffers &b) noexcept {
            return static_cast<buffers>(static_cast<int>(a) & static_cast<int>(b));
        }
        
        constexpr bool operator&&(const buffers &a, const buffers &b) noexcept {
            return static_cast<int>(a & b) != 0;
        }
        
        void clear(buffers bitmask);
    }
}
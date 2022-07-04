#ifndef RGRAPHICS_BUFFER_HPP
#define RGRAPHICS_BUFFER_HPP

#include <span>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace rgraphics {
    struct Buffer {
        template <typename T>
        Buffer(GLenum type, std::span<T const> data)
                : m_type{type}, m_size{data.size()} {
            glGenBuffers(1, &m_id);
            glBindBuffer(m_type, m_id);
            glBufferData(m_type, data.size() * sizeof(T), data.data(), GL_STATIC_DRAW);
        }

        Buffer(Buffer const& rhs) = delete;
        Buffer(Buffer&& rhs) noexcept;
        Buffer& operator=(Buffer const& rhs) = delete;
        Buffer& operator=(Buffer&& rhs) noexcept;

        ~Buffer();

        void bind();
        void unbind();

    private:
        uint32_t m_id;
        GLenum m_type;
        size_t m_size;
    };
}


#endif  // RGRAPHICS_BUFFER_HPP

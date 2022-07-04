#ifndef RGRAPHICS_VERTEX_ARRAY_HPP
#define RGRAPHICS_VERTEX_ARRAY_HPP

#include <span>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "buffer.hpp"
#include "vertex_layout.hpp"


namespace rgraphics {
    struct VertexArray {
        template <typename T>
        VertexArray(std::span<T const> data, std::span<uint32_t const> indices, VertexLayout const& layout)
            : m_vbo{GL_ARRAY_BUFFER, data}, m_ibo{GL_ELEMENT_ARRAY_BUFFER, indices} {
            glGenVertexArrays(1, &m_id);
            glBindVertexArray(m_id);

            layout.apply();
        }

        void bind();
        void unbind();

    private:
        uint32_t m_id;
        Buffer m_vbo, m_ibo;
    };
}


#endif  // RGRAPHICS_VERTEX_ARRAY_HPP

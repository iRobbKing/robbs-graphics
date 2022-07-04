#include "vertex_layout.hpp"


namespace {
    size_t size_of_gl_type(GLenum type) {
        switch (type) {
            case GL_BYTE:
                return sizeof(char);
            case GL_UNSIGNED_BYTE:
                return sizeof(unsigned char);
            case GL_SHORT:
                return sizeof(short);
            case GL_UNSIGNED_SHORT:
                return sizeof(unsigned short);
            case GL_INT:
                return sizeof(int);
            case GL_UNSIGNED_INT:
                return sizeof(unsigned int);
            default:
                assert(false);
        }
    }
}


namespace rgraphics {
    VertexLayout::VertexLayout(std::vector<uint8_t> layout, GLenum type)
            : m_layout{std::move(layout)}, m_type{type} {}

    void VertexLayout::apply() const {
        auto elem_size{size_of_gl_type(m_type)};
        auto stride{std::accumulate(m_layout.begin(), m_layout.begin(), 0) * elem_size};

        for (int i{0}, offset{0}; i < m_layout.size(); ++i) {
            uint8_t attr_length{m_layout[i]};

            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, attr_length, m_type, GL_FALSE, stride, reinterpret_cast<const void*>(offset));

            offset += attr_length * elem_size;
        }
    }
}

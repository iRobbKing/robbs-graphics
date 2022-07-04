#include "vertex_array.hpp"


namespace rgraphics {
    void VertexArray::bind() {
        glBindVertexArray(m_id);
        m_vbo.bind();
        m_ibo.bind();
    }

    void VertexArray::unbind() {
        glBindVertexArray(0);
        m_vbo.unbind();
        m_ibo.unbind();
    }
}

#include "buffer.hpp"


namespace rgraphics {
    Buffer::Buffer(Buffer&& rhs) noexcept
        : m_id{rhs.m_id}, m_type{rhs.m_type}, m_size{rhs.m_size} {
        rhs.m_id = 0;
    }

    Buffer& Buffer::operator=(Buffer&& rhs) noexcept {
        m_id = rhs.m_id;
        m_type = rhs.m_type;
        m_size = rhs.m_size;
        rhs.m_id = 0;
        return *this;
    }

    Buffer::~Buffer() {
        glDeleteBuffers(1, &m_id);
    }

    void Buffer::bind() {
        glBindBuffer(m_type, m_id);
    }

    void Buffer::unbind() {
        glBindBuffer(m_type, 0);
    }
}

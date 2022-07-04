#ifndef RGRAPHICS_VERTEX_LAYOUT_HPP
#define RGRAPHICS_VERTEX_LAYOUT_HPP

#include <cassert>
#include <cstdint>
#include <numeric>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace rgraphics {
    struct VertexLayout {
        VertexLayout(std::vector<uint8_t> layout, GLenum type);

        void apply() const;

    private:
        std::vector<uint8_t> m_layout;
        GLenum m_type;
    };
}


#endif  // RGRAPHICS_VERTEX_LAYOUT_HPP

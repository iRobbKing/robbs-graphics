#include <iostream>

#include "src/shader_lib.hpp"
#include "src/window.hpp"


int main() {
    std::string const shader{
        "#shader vertex\n"
        "#version 450 core\n"
        "\n"
        "layout(location=0) in vec3 a_position;\n"
        "layout(location=1) in vec2 a_uv;\n"
        "\n"
        "uniform mat4 u_mvp;\n"
        "\n"
        "layout(location=0) out vec2 f_uv;\n"
        "\n"
        "void main() {\n"
        "    gl_Position = v_mvp * vec4(a_position, 1.0);\n"
        "    f_uv = a_uv;\n"
        "}\n"
        "\n"
        "#shader fragment\n"
        "#version 450 core\n"
        "\n"
        "layout(location=0) in vec2 f_uv;\n"
        "\n"
        "layout(location=0) out vec4 o_color;\n"
        "\n"
        "uniform sampler2D u_texture;\n"
        "\n"
        "void main() {\n"
        "    o_color = vec4(texture(u_texture, f_uv).rgb, 1.0);\n"
        "}\n"
    };

    std::vector<std::string_view> shaders{shader};

    rgraphics::ShaderLib lib{shaders};

    // auto window{rgraphics::make_window(800, 600, "Window.")};

    // while (!window->should_close()) {
    //     window->swap_buffers();
    //     rgraphics::poll_events();
    // }
}

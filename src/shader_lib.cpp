#include "shader_lib.hpp"
#include <iostream>


namespace {
    unique_generator<std::string_view> get_lines(std::string_view shader) {
        size_t pos{0};
        size_t new_line_pos;
        while ((new_line_pos = shader.find('\n', pos)) != std::string::npos) {
            co_yield shader.substr(pos, new_line_pos - pos);
            pos = new_line_pos + 1;
        }
    }
}


namespace rgraphics {
    ShaderLib::ShaderLib(std::span<std::string_view> shaders) {
        for (std::string_view shader: shaders) {
            std::unordered_map<std::string, std::string> sub_shaders{};

            for (std::string_view line: get_lines(shader)) {
                std::cout << line << '\n';
            }
        }
    }
}

#ifndef RGRAPHICS_SHADER_LIB_HPP
#define RGRAPHICS_SHADER_LIB_HPP

#include <filesystem>
#include <fstream>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

#include <coro/unique_generator.h>

#include "shader.hpp"


namespace rgraphics {
    struct ShaderLib {
        ShaderLib(std::span<std::string_view> shaders);

    private:
        std::vector<Shader> m_shaders{};
    };
}


#endif  // RGRAPHICS_SHADER_LIB_HPP

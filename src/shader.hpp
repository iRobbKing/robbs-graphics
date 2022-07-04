#ifndef RGRAPHICS_SHADER_HPP
#define RGRAPHICS_SHADER_HPP

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace rgraphics {
    struct Shader {
    private:
        friend std::variant<std::string, std::shared_ptr<Shader>>
        make_shader(std::unordered_map<GLenum, std::string> const& sources);

        Shader(uint32_t id);

        void bind();
        void unbind();

    private:
        uint32_t m_id;
    };


    std::variant<std::string, std::shared_ptr<Shader>>
    make_shader(std::unordered_map<GLenum, std::string> const& sources);
}


#endif  // RGRAPHICS_SHADER_HPP

#include "shader.hpp"


namespace {
    std::string get_shader_error_message(uint32_t id) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        std::string message{};
        message.reserve(length);
        glGetShaderInfoLog(id, length, &length, message.data());
        return message;
    }


    std::optional<std::string> validate_shader(uint32_t id) {
        int result;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_TRUE)
            return std::nullopt;

        return get_shader_error_message(id);
    }


    std::variant<std::string, uint32_t> compile_shader(std::string const& data, uint32_t type) {
        char const* src{data.data()};

        uint32_t id{glCreateShader(type)};
        glShaderSource(id, 1, &src, nullptr);
        glCompileShader(id);

        if (auto not_valid{validate_shader(id)}; not_valid.has_value()) {
            glDeleteShader(id);
            return not_valid.value();
        }

        return id;
    }


    std::string get_program_error_message(uint32_t id) {
        int length;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);
        std::string message{};
        message.reserve(length);
        glGetProgramInfoLog(id, length, &length, message.data());
        return message;
    }


    std::optional<std::string> validate_program(uint32_t id) {
        GLint result;
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        if (result == GL_FALSE)
            return get_program_error_message(id);

        glValidateProgram(id);
        glGetProgramiv(id, GL_VALIDATE_STATUS, &result);
        if (result == GL_FALSE)
            return get_program_error_message(id);

        return std::nullopt;
    }

    std::variant<std::string, uint32_t> link_program(std::vector<uint32_t> const& shaders) {
        uint32_t id{glCreateProgram()};

        for (uint32_t shader: shaders)
            glAttachShader(id, shader);

        glLinkProgram(id);

        if (auto not_valid{validate_program(id)}; not_valid.has_value()) {
            glDeleteProgram(id);
            return not_valid.value();
        }

        return id;
    }
}


namespace rgraphics {
    Shader::Shader(uint32_t id)
            : m_id{id} {}

    void Shader::bind() {
        glUseProgram(m_id);
    }

    void Shader::unbind() {
        glUseProgram(0);
    }

    std::variant<std::string, std::shared_ptr<Shader>>
    make_shader(std::unordered_map<GLenum, std::string> const& sources) {
        std::vector<uint32_t> shaders;
        for (auto const& [type, source]: sources) {
            auto compiled_shader{compile_shader(source, type)};

            if (std::holds_alternative<std::string>(compiled_shader))
                return std::get<std::string>(compiled_shader);

            shaders.push_back(std::get<uint32_t>(compiled_shader));
        }

        auto program{link_program(shaders)};
        if (std::holds_alternative<std::string>(program))
            return std::get<std::string>(program);

        uint32_t program_id{std::get<uint32_t>(program)};
        for (uint32_t shader: shaders) {
            glDetachShader(program_id, shader);
            glDeleteShader(shader);
        }

        return std::shared_ptr<Shader>(new Shader{program_id});
    }
}

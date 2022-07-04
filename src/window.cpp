#include "window.hpp"


namespace {
    bool g_inited_libs{false};
}


namespace rgraphics {
    std::shared_ptr<Window> make_window(int width, int height, std::string title) {
        if (!g_inited_libs && glfwInit() != GLFW_TRUE)
            return nullptr;

        auto window{std::shared_ptr<Window>{new Window{width, height, std::move(title)}}};
        window->activate_context();

        if (!g_inited_libs && !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            return nullptr;

        g_inited_libs = true;
        return window;
    }

    Window::Window(int width, int height, std::string title)
            : m_width{width}, m_height{height}, m_title{std::move(title)},
            m_window{glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr)} {}

    void Window::activate_context() {
        glfwMakeContextCurrent(m_window);
    }

    void Window::swap_buffers() {
        glfwSwapBuffers(m_window);
    }

    bool Window::should_close() {
        return glfwWindowShouldClose(m_window);
    }

    void poll_events() {
        glfwPollEvents();
    }
}

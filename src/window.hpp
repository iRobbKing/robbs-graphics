#ifndef RGRAPHICS_WINDOW_HPP
#define RGRAPHICS_WINDOW_HPP

#include <memory>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace rgraphics {
    struct Window {
        void activate_context();
        void swap_buffers();
        bool should_close();

    private:
        friend std::shared_ptr<Window> make_window(int width, int height, std::string title);

        Window(int width, int height, std::string title);

    private:
        int m_width, m_height;
        std::string m_title;

        GLFWwindow* m_window;
    };

    std::shared_ptr<Window> make_window(int width, int height, std::string title);

    void poll_events();
}


#endif  // RGRAPHICS_WINDOW_HPP

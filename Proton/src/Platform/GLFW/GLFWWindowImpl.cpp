#include "pnpch.h"
#include "GLFWWindowImpl.h"

namespace Proton {
    Window* Window::Create(const WindowProps& props) {
        return new GLFWWindowImpl(props);
    }

    GLFWWindowImpl::GLFWWindowImpl(const WindowProps& props) { Init(props); }

    GLFWWindowImpl::~GLFWWindowImpl() { Shutdown(); }

    void GLFWWindowImpl::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        int success = glfwInit();
        std::cout << "GLFW init: " << success << std::endl;

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height,
                                    m_Data.Title.c_str(), nullptr,
                                    nullptr); // Create GLFW window
        glfwMakeContextCurrent(m_Window);     // Set Current context
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        std::cout << "Glad status: " << status << std::endl;
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void GLFWWindowImpl::Shutdown() { glfwDestroyWindow(m_Window); }

    void GLFWWindowImpl::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void GLFWWindowImpl::SetVSync(bool enable) {
        if (enable)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enable;
    }

    bool GLFWWindowImpl::IsVSync() const { return m_Data.VSync; }
} // namespace Proton

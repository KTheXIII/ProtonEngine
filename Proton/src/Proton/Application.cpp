#include "pnpch.h"
#include "Application.h"

#include "glad/glad.h"

namespace Proton {

    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {}

    void Application::Run() {
        while (m_Running) {
            glClearColor(255. / 255., 66. / 255., 98. / 255., 1);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->OnUpdate();
        }
    }

} // namespace Proton

#pragma once
#include "Proton/Window.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Proton {
    class GLFWWindowImpl : public Window {
      public:
        GLFWWindowImpl(const WindowProps& props);
        virtual ~GLFWWindowImpl();

        virtual void OnUpdate() override;

        inline virtual unsigned int GetWidth() const override {
            return m_Data.Width;
        }

        inline virtual unsigned int GetHeight() const override {
            return m_Data.Height;
        }

        virtual void SetVSync(bool enable) override;
        virtual bool IsVSync() const override;

      private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

        struct WindowData {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool VSync;
        };

        GLFWwindow* m_Window;
        WindowData m_Data;
    };
} // namespace Proton

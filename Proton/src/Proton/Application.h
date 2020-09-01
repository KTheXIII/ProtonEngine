#pragma once

#include "Core.h"

#include "Window.h"

namespace Proton {

    class PROTON_API Application {
      public:
        Application();
        virtual ~Application();

        void Run();

        inline Window& GetWindow() {
            return *m_Window;
        } // Return dereferenced pointer
        inline Application& Get() {
            return *s_Instance;
        } // Return dereferenced pointer

      private:
        std::unique_ptr<Window> m_Window; // Creates window pointer
        bool m_Running = true;

        static Application* s_Instance; // Create this instance unique pointer
    };

    Application* CreateApplication();
} // namespace Proton

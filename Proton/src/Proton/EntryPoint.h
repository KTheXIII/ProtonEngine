#pragma once

extern Proton::Application* Proton::CreateApplication();

int main(int argc, char** argv) {
    auto app = Proton::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

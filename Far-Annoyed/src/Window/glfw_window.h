#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

#include "KeyListner.h"

namespace Breaker
{
    struct WinProps
    {
        int width;
        int height;
        const char* name;
        GLFWwindow *window = nullptr;

        WinProps(int w = 900, int h = 700, const char* name = "Far-Annoyed")
            : width(w), height(h), name(name)
        {
        }
    };

    class Window
    {
    public:
        Window(const WinProps& props);
        ~Window();

        static std::unique_ptr<Window> CreateWindow(const WinProps& props = WinProps());

        void OnUpdate();
        bool IsShouldClose() const;
        const WinProps &GetWindowProps();

    private:
        WinProps props;

        void Init();
    };
}
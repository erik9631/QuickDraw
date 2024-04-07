//
// Created by erik9 on 4/6/2024.
//
#include <windows.h>
#include "Ui/Component/Win32Window.h"
#include "Win32.h"
#include <iostream>
#include <mutex>

#if defined(_M_X64)
#define USER_DATA (GWLP_USERDATA)
#else
#define USER_DATA (GWL_USERDATA)
#endif

using namespace backend;
using namespace ui::component;

void ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, Win32Window* window){
    switch (uMsg){
    case WM_CLOSE:
        PostQuitMessage(0);
        window->core.windowHandle = nullptr;
        break;
    case WM_SIZE:
        window->SetSize(glm::vec3(LOWORD(lParam), HIWORD(lParam), window->GetElement().size.z));
        break;
    default:
        break;
    }
}

LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    auto* window = reinterpret_cast<Win32Window*>(GetWindowLongPtr(hwnd, USER_DATA));
    if (window != nullptr)
        ProcessMessage(uMsg, wParam, lParam, window);

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void MessageLoop(const Win32Window& window) {
    while(window.core.windowHandle != nullptr){
        MSG msg = {};
        GetMessage(&msg, window.core.windowHandle, 0, 0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

std::unique_ptr<ui::component::Win32Window> _CreateCore(const glm::vec3& pos, const glm::vec3& size, const std::string &windowName) {
    auto hInstance = GetModuleHandleA(nullptr);
    auto win32Window = std::make_unique<Win32Window>();
    memset(&win32Window->core.windowClass, 0, sizeof(WNDCLASS));
    win32Window->core.windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    win32Window->core.windowClass.lpfnWndProc = WindowProc;
    win32Window->core.windowClass.cbClsExtra = NULL;
    win32Window->core.windowClass.cbWndExtra = NULL;
    win32Window->core.windowClass.hInstance = hInstance;
    win32Window->core.windowClass.hIcon = NULL;
    win32Window->core.windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    win32Window->core.windowClass.hbrBackground = NULL;
    win32Window->core.windowClass.lpszMenuName = NULL;
    win32Window->core.windowClass.lpszClassName = windowName.c_str();

    if (!RegisterClass(&win32Window->core.windowClass))
    {
        std::cout << "Register Class error: " << GetLastError() << std::endl;
        system("PAUSE");
        exit(0);
    }
    win32Window->core.windowHandle = CreateWindow(
        win32Window->core.windowClass.lpszClassName, win32Window->core.windowClass.lpszClassName,
        WS_OVERLAPPEDWINDOW , pos.x, pos.y, size.x, size.y, nullptr, nullptr, hInstance, nullptr
        );

    if (!win32Window->core.windowHandle)
    {
        std::cout << "Error creating window handle " << GetLastError() << std::endl;
        system("PAUSE");
        exit(0);
    }
    auto win32WindowRef = win32Window.get();

    SetWindowLongPtr(win32Window->core.windowHandle, USER_DATA, (LONG_PTR)win32WindowRef);
    ShowWindow(win32Window->core.windowHandle, SW_SHOW);
    UpdateWindow(win32Window->core.windowHandle);
    return win32Window;
}


namespace backend{
    std::unique_ptr<ui::component::Win32Window> CreateCore(const glm::vec3& pos, const glm::vec3& size, const std::string &windowName) {
        std::mutex initMutex;
        std::condition_variable initSignal;
        bool initIncomplete = false;
        std::unique_ptr<Win32Window> win32Window;

        auto t = new std::thread ([&] {
            win32Window = _CreateCore(pos, size, windowName);
            std::unique_lock lock(initMutex);
            initSignal.notify_one();
            initIncomplete = true;
            lock.unlock();
            MessageLoop(*win32Window);
        });
        std::unique_lock lock(initMutex);
        initSignal.wait(lock, [&] { return initIncomplete; });
        win32Window->core.runningThreads.push_back(t);
        return win32Window;
    }
}

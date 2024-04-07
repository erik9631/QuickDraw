//
// Created by erik9 on 4/7/2024.
//

#ifndef WIN32CORE_H
#define WIN32CORE_H
#include <windows.h>
#include <thread>
#include <vector>
#define MAX_CPUS 32


namespace backend {
    struct Win32Core {
        WNDCLASS windowClass = {};
        HWND windowHandle = nullptr;
        std::vector<std::thread*> runningThreads;
        ~Win32Core();
    };

}


#endif //WIN32CORE_H

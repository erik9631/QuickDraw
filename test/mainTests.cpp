//
// Created by erik9 on 4/6/2024.
//

#include <catch_amalgamated.hpp>"
#include <Backend/Win32.h>
#include <Ui/Component/Win32Window.h>

#include "Backend/Backend.h"

TEST_CASE("Win32Window test", "[Win32Window test]") {
    auto window = backend::CreateCore({0, 0, 0}, {800, 600, 0}, "TestWindow");
    CHECK(strcmp(window->core.windowClass.lpszClassName, "TestWindow") == 0);

    JoinThreads(*window);
}
#include <Backend/Win32.h>
#include <Ui/Component/Win32Window.h>

#include "Backend/Backend.h"
#include "Ui/Component/Api/ElementApi.h"

using namespace backend;

int main() {
    auto core = CreateCore(glm::vec3(0, 0, 0),
        glm::vec3(800, 600, 0), "Test Window");
    JoinThreads(*core);
    return 0;
}

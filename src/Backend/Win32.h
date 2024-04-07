//
// Created by erik9 on 4/6/2024.
//

#ifndef WIN32_H
#define WIN32_H
#include <memory>
#include <string>
#include <glm.hpp>

namespace ui::component{
    class Win32Window;
}


namespace backend{
    std::unique_ptr<ui::component::Win32Window> CreateCore(const glm::vec3& pos, const glm::vec3& size, const std::string &windowName);

}

#endif //WIN32_H

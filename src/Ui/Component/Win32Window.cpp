//
// Created by erik9 on 4/6/2024.
//
#include "Win32Window.h"
#include "Ui/Component/Utils.h"


const ui::component::Element & ui::component::Win32Window::GetElement() const {
    return element;
}

void ui::component::Win32Window::SetPosition(const glm::vec3 &position, bool emit) {
    element.position = position;
    auto src = std::make_any<Win32Window*>(this);
}

void ui::component::Win32Window::SetSize(const glm::vec3 &size, bool emit) {
    element.size = size;
    auto src = std::make_any<Win32Window*>(this);
}

void ui::component::Win32Window::SetName(const std::string& name, bool emit) {
    element.name = name;
}

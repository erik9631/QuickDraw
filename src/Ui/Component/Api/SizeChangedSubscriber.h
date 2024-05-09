//
// Created by erik9 on 4/27/2024.
//

#ifndef SIZECHANGEDSUBSCRIBER_H
#define SIZECHANGEDSUBSCRIBER_H
#include <glm.hpp>
#include <any>
#include <functional>
namespace ui::component::api {
    typedef std::function<void (const glm::vec3&, std::any&)> SizeChangedSubscriber;
}
#endif //SIZECHANGEDSUBSCRIBER_H

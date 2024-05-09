//
// Created by erik9 on 4/27/2024.
//

#ifndef POSITIONCHANGEDSUBSCRIBER_H
#define POSITIONCHANGEDSUBSCRIBER_H
#include <any>
#include <glm.hpp>

namespace ui::component::api {
    typedef std::function<void (const glm::vec3&, std::any&)> PositionChangedSubscriber;
}


#endif //POSITIONCHANGEDSUBSCRIBER_H

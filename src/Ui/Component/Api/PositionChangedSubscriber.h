//
// Created by erik9 on 4/27/2024.
//

#ifndef POSITIONCHANGEDSUBSCRIBER_H
#define POSITIONCHANGEDSUBSCRIBER_H
#include <any>
#include <glm.hpp>



namespace ui::component::api {
    class PositionChangedSubscriber {
    public:
        virtual void OnSizeChanged(const glm::vec3& size, std::any& src) = 0;
        virtual ~PositionChangedSubscriber() = default;
    };
}


#endif //POSITIONCHANGEDSUBSCRIBER_H

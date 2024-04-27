//
// Created by erik9 on 4/27/2024.
//

#ifndef SIZECHANGEDSUBSCRIBER_H
#define SIZECHANGEDSUBSCRIBER_H
#include <glm.hpp>
#include <any>

namespace ui::component::api {
    class SizeChangedSubscriber {
    public:
        virtual void OnSizeChanged(const glm::vec3& size, std::any& src) = 0;
        virtual ~SizeChangedSubscriber() = default;
    };
}
#endif //SIZECHANGEDSUBSCRIBER_H

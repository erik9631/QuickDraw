//
// Created by erik9 on 4/6/2024.
//

#ifndef WINDOW_H
#define WINDOW_H
#include "Api/ElementApi.h"
#include "Backend/Win32Core.h"
#include "Ui/Component/Api/PositionChangedSubscriber.h"
#include <iostream>

namespace ui::component{
    class Win32Window final : public api::ElementApi{
        Element element = {};
    public:
        backend::Win32Core core = {};
        std::vector<api::SizeChangedSubscriber> sizeChangedSubscribers = {};
        std::vector<api::PositionChangedSubscriber> positionChangedSubscribers = {};
        [[nodiscard]] const Element & GetElement() const override;
        void SetPosition(const glm::vec3 & position, bool emit = true) override;
        void SetSize(const glm::vec3 & size, bool emit = true) override;
        void SetName(const std::string& name, bool emit = true) override;
        ~Win32Window() override = default;
    };
}
#endif //WINDOW_H

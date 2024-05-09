//
// Created by erik9 on 4/6/2024.
//

#ifndef ELEMENTAPI_H
#define ELEMENTAPI_H
#include <glm.hpp>
#include "Ui/Component/Element.h"
namespace ui::component::api {
    struct ElementApi {
        virtual void SetPosition(const glm::vec3&, bool emit) = 0;
        virtual void SetSize(const glm::vec3&, bool emit) = 0;
        virtual void SetName(const std::string&, bool emit) = 0;
        [[nodiscard]] virtual const Element& GetElement() const = 0;
        virtual ~ElementApi() = default;

    };
}


#endif //ELEMENTAPI_H

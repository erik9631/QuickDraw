//
// Created by erik9 on 4/6/2024.
//

#ifndef ELEMENTAPI_H
#define ELEMENTAPI_H
#include <glm.hpp>
#include "Ui/Component/Element.h"
namespace ui::component::api {
    template<typename ElementApi>
    concept ElementApiConcept = requires(ElementApi e, const glm::vec3& v, bool emit, Element element, std::string name){
        {e.SetPosition(v, emit)} -> std::same_as<void>;
        {e.SetSize(v, emit)} -> std::same_as<void>;
        {e.GetElement()} -> std::same_as<const Element&>;
        {e.SetName(name, emit)} -> std::same_as<void>;
    };

    struct ElementApi {
        virtual void SetPosition(const glm::vec3&, bool emit) = 0;
        virtual void SetSize(const glm::vec3&, bool emit) = 0;
        virtual void SetName(const std::string&, bool emit) = 0;
        [[nodiscard]] virtual const Element& GetElement() const = 0;
        virtual ~ElementApi() = default;

    };
}


#endif //ELEMENTAPI_H

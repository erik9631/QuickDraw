//
// Created by erik9 on 4/6/2024.
//

#ifndef ELEMENT_H
#define ELEMENT_H
#include <glm.hpp>
#include <string>
#include <vector>

#include "Ui/Component/Api/SizeChangedSubscriber.h"

namespace ui::component{
    struct Element{
        std::vector<api::SizeChangedSubscriber*> sizeChangedSubscribers = {};
        glm::vec3 position = {};
        glm::vec3 size = {};
        std::string name = {};
    };

}


#endif //ELEMENT_H

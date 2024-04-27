//
// Created by erik9 on 4/27/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include <any>
#include <vec3.hpp>
#include <vector>

#include "Api/PositionChangedSubscriber.h"
#include "Api/SizeChangedSubscriber.h"

namespace ui::component {
    static void DispatchOnSizeChanged(const glm::vec3& size, std::any& src, std::vector<api::SizeChangedSubscriber>& subscribers){
        for(auto& subscriber : subscribers){
            subscriber.OnSizeChanged(size, src);
        }
    }

    static void DispatchOnPositionChanged(const glm::vec3& size, std::any& src, std::vector<api::PositionChangedSubscriber>& subscribers){
        for(auto& subscriber : subscribers){
            subscriber.OnSizeChanged(size, src);
        }
    }

}


#endif //UTILS_H

//
// Created by erik9 on 4/7/2024.
//

#ifndef CORE_API_CONCEPT_H
#define CORE_API_CONCEPT_H
#include <vector>
#include <thread>

namespace backend::api {
    template<typename CoreApi>
    concept CoreApiConcept = requires(CoreApi c){
        {c.core.runningThreads} -> std::convertible_to<std::vector<std::thread*>>;
    };
}

#endif //CORE_API_CONCEPT_H

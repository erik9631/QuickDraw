//
// Created by erik9 on 4/7/2024.
//

#ifndef BACKEND_H
#define BACKEND_H
#include "Api/CoreApiConcept.h"

template <backend::api::CoreApiConcept T>
void JoinThreads(T& coreWrapper){
    for (auto* thread : coreWrapper.core.runningThreads){
        if (thread->joinable())
            thread->join();
    }
}

#endif //BACKEND_H

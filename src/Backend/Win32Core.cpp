//
// Created by erik9 on 4/7/2024.
//

#include "Win32Core.h"

#include <iostream>
using namespace backend;

Win32Core::~Win32Core() {
    for (auto* thread : runningThreads){
        if (thread->joinable())
            thread->join();
    }
}

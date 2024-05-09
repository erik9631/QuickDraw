//
// Created by erik9 on 5/9/2024.
//

#ifndef QUICKDRAW_REACTIVE_H
#define QUICKDRAW_REACTIVE_H
#include <vector>
#include <any>
#include <functional>

namespace utils{
    struct DefaultSource{};

    template <typename T, typename K = DefaultSource>
    class Reactive{
        T val;
        K src;
    public:
        std::vector<std::function<void(T, std::any&)>> subscribers;
        explicit Reactive(T val): val(val) {}
        Reactive(T val, K src): val(val), src(src) {}

        template <typename U>
        Reactive& operator=(U newVal) {
            val = newVal;
            for (auto& subscriber : subscribers) {
                auto anyType = std::make_any<K*>(&src);
                subscriber(val, anyType);
            }
            return *this;
        }

        template <typename U>
        Reactive& operator+=(U newVal) {
            val += newVal;
            for (auto& subscriber : subscribers) {
                auto anyType = std::make_any<K*>(&src);
                subscriber(val, anyType);
            }
            return *this;
        }

        template <typename U>
        Reactive& operator-=(U newVal) {
            val -= newVal;
            for (auto& subscriber : subscribers) {
                auto anyType = std::make_any<K*>(&src);
                subscriber(val, anyType);
            }
            return *this;
        }

        template <typename U>
        Reactive& operator*=(U newVal) {
            val *= newVal;
            for (auto& subscriber : subscribers) {
                auto anyType = std::make_any<K*>(&src);
                subscriber(val, anyType);
            }
            return *this;
        }

        template <typename U>
        Reactive& operator/=(U newVal) {
            val /= newVal;
            for (auto& subscriber : subscribers) {
                auto anyType = std::make_any<K*>(&src);
                subscriber(val, anyType);
            }
            return *this;
        }

    };
}



#endif //QUICKDRAW_REACTIVE_H

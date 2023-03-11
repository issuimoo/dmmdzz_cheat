#pragma once
#include <vector>

template<typename T>
class vector_thl {
    std::vector<T> mvec;
public:

    thread_local static std::vector<T> vec;

    vector_thl() = default;
    vector_thl(const vector_thl& vec) {
        mvec = vec;
        vec = vec;
    };
    vector_thl(vector_thl&& vec) {
        mvec = vec;
        vec = vec;
    };


    void push_back(const T& value) noexcept {
        vec.push_back(value);
    }

    void merge() {
        mvec.insert(mvec.end(), vec.begin(), vec.end());
    }

    void getVector(std::vector<T>& res) {
        res = mvec;
    }
};

template<typename T>
thread_local std::vector<T> vector_thl<T>::vec(0);
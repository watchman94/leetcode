//
// Created by Kiven on 2021/10/23.
//

#ifndef LEETCODE_UNIQUEPTR_H
#define LEETCODE_UNIQUEPTR_H

using namespace std;

template<typename T, typename deleateFunc>
class UniquePtr{
    T* ptr;
    deleateFunc df;
public:
    explicit UniquePtr(T* p = nullptr): ptr(p){}
    explicit UniquePtr(T* p, deleateFunc df): ptr(p), df(df){}
    UniquePtr(const UniquePtr& up) = delete;
    UniquePtr& operator=(const UniquePtr& up) = delete;
    UniquePtr(UniquePtr&& up){
        ptr = up.ptr;
        up.ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& up){
        if(up->ptr != this->ptr) swap(up->ptr, this->ptr);
        up.release();
        return *this;
    }
    void reset(T* p = nullptr){
        T* tmp = ptr;
        ptr = p;
        delete(tmp);
    }


};

#endif //LEETCODE_UNIQUEPTR_H

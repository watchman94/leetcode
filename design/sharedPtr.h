//
// Created by Kiven on 2021/10/26.
//

#ifndef LEETCODE_SHAREDPTR_H
#define LEETCODE_SHAREDPTR_H

#include <iostream>
using namespace std;

template <typename T>
class SharedPtr{
    T* ptr;
    int cnt;
    void release(){
        cnt--;
        if(!cnt){
            delete(ptr);
            ptr = nullptr;
        }
    }
public:
    explicit SharedPtr(T* ptr = nullptr, int cnt = 0):ptr(ptr), cnt(cnt){};
    SharedPtr(const SharedPtr& sp){
        ptr = sp.ptr;
        sp.cnt++;
        cnt = sp.cnt;
    }
    SharedPtr& operator=(const SharedPtr& sp){
        if(ptr != sp.ptr){
            release();
            ptr = sp.ptr;
            sp.cnt++;
            cnt = sp.cnt;
        }
        return *this;
    }
    SharedPtr(SharedPtr&& sp) {
        ptr = sp.ptr;
        cnt = sp.cnt;
        sp.ptr = nullptr;
        sp.cnt = 0;
    }
    SharedPtr& operator=(SharedPtr&& sp){
        if(ptr != sp.ptr){
            release();
            ptr = sp.ptr;
            cnt = sp.cnt;
            sp.ptr = nullptr;
            sp.cnt = 0;
        }
        return *this;
    }
    ~SharedPtr(){
        release();
    }
};

#endif //LEETCODE_SHAREDPTR_H

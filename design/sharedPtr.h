//
// Created by Kiven on 2021/10/26.
//

#ifndef LEETCODE_SHAREDPTR_H
#define LEETCODE_SHAREDPTR_H

#include <iostream>
using namespace std;

class Count{
	int cnt;
	public:
	Count(){cnt = 1;}
	void inc(){cnt++;}
	void dec(){cnt--;}
	operator int(){return cnt;};
};

template <typename T>
class SharedPtr{
    T* ptr;
    Count* cnt;
    void release() noexcept{
        cnt->dec();
        if(*cnt == 0){
	    cout << "remove num: " << *ptr << endl;
            delete(ptr);
	    delete(cnt);
            ptr = nullptr;
	    cnt = nullptr;
        }
    }
public:
    explicit SharedPtr(T* ptr = nullptr):ptr(ptr), cnt(new Count()){};
    SharedPtr(const SharedPtr& sp) noexcept{
        ptr = sp.ptr;
        sp.cnt->inc();
        cnt = sp.cnt;
    }

    SharedPtr& operator=(SharedPtr tmp) noexcept{
    	this->swap(tmp);
	return *this;
    }

    void swap(SharedPtr& tmp) noexcept{
    	using std::swap;
	swap(this->ptr, tmp.ptr);
	swap(this->cnt, tmp.cnt);
    }
	
    /*
    SharedPtr& operator=(const SharedPtr& sp){
        if(ptr != sp.ptr){
            release();
            ptr = sp.ptr;
            sp.cnt++;
            cnt = sp.cnt;
        }
        return *this;
    }
    */

    SharedPtr(SharedPtr&& sp) noexcept{
        ptr = sp.ptr;
        cnt = sp.cnt;
        sp.ptr = nullptr;
        sp.cnt = nullptr;
    }

    /*
    SharedPtr& operator=(SharedPtr&& sp){
        if(ptr != sp.ptr){
            release();
            ptr = sp.ptr;
            cnt = sp.cnt;
            sp.ptr = nullptr;
            //sp.cnt = 0;
        }
        return *this;
    }
    */

    ~SharedPtr() noexcept{
	if(ptr) release();
    }
    operator bool(){
        return ptr != nullptr;
    }
    T* operator->(){
        return ptr;
    }
    T& operator*(){
        return *ptr;
    }
    T* get(){
        return ptr;
    }
    void reset(T* p = nullptr) noexcept{
        release();
        ptr = p;
        if(ptr) cnt = new Count();
    }
    int use_count(){
	return cnt ? *cnt : 0;
    }
};

template<typename T>
void swap(SharedPtr<T>& s1, SharedPtr<T>& s2){
	s1.swap(s2);
}

template<typename T, typename... Args>
auto make_shared(Args&&... args){
	return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

void test(){
	cout << "test copy " << endl;
	SharedPtr<int> sp1(new int(1));
	(*sp1)++;
	cout << "sp1 num: " << *sp1 << endl;
	cout << "sp1 use count: " << sp1.use_count() << endl;
	SharedPtr<int> sp2(sp1);
	cout << "sp2 num: " << *sp2 << endl;
	cout << "sp2 use count: " << sp2.use_count() << endl;
	cout << "sp1 use count: " << sp1.use_count() << endl;
	SharedPtr<int> sp3(new int(3));
	cout << "sp3 num: " << *sp3 << endl;
	cout << "sp3 use count: " << sp3.use_count() << endl;
	sp3 = sp1;
	cout << "sp3 use count: " << sp3.use_count() << endl;
	cout << "sp1 use count: " << sp1.use_count() << endl;
	
	cout << endl;
	cout << "test move" << endl;
	SharedPtr<int> sp4(new int(4));
	cout << "sp4 num: " << *sp4 << endl;
	cout << "sp4 use count: " << sp4.use_count() << endl;
	SharedPtr<int> sp5(move(sp4));
	cout << "sp5 num: " << *sp5 << endl;
	cout << "sp5 use count: " << sp5.use_count() << endl;

	
	SharedPtr<int> sp6 = make_shared<int>(6);
	SharedPtr<int> sp7(sp6);
	cout << "sp7 num: " << *sp7 << endl;
	cout << "sp7 use count: " << sp7.use_count() << endl;

		
	SharedPtr<int> sp8 = make_shared<int>(8);
	sp8 = move(sp7);
	//cout << "sp7 num: " << *sp7 << endl;
	cout << "sp7 use count: " << sp7.use_count() << endl;
	cout << "sp8 num: " << *sp8 << endl;
	cout << "sp8 use count: " << sp8.use_count() << endl;
	cout << "sp6 num: " << *sp6 << endl;
	cout << "sp6 use count: " << sp6.use_count() << endl;
	

}

#endif //LEETCODE_SHAREDPTR_H

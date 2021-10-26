#include<iostream>
using namespace std;

template<typename T>
void defaultDel(T* p){
	cout << "in deletor func: clear " << *p << endl;
	delete(p);
}

class Deletor1{
public:
	template<typename T>
	void operator()(T* p){
		cout << "in deletor class 1: clear " << *p << endl;
		delete(p);
	}
};

class Deletor2{
public:
	template<typename T>
	void operator()(T* p){
		cout << "in deletor class 2: clear " << *p << endl;
		delete(p);
	}
};
template<typename T, typename F = Deletor1>
class UniquePtr{
	T* ptr;
	F del;
	void release() noexcept{
		if(ptr){
			del(ptr);
			//delFunc();
			ptr = nullptr;
			//delFunc = nullptr;
		}	
	}
public:
	explicit UniquePtr(T* ptr = nullptr): ptr(ptr){}
	UniquePtr(const UniquePtr& upr) = delete;
	UniquePtr& operator=(const UniquePtr& upr) = delete;
	UniquePtr(UniquePtr&& upr) noexcept{
		ptr = upr.ptr;
		del = upr.del;
		upr.ptr = nullptr;
		//upr.del = nullptr;
	}
	UniquePtr& operator=(UniquePtr&& upr) noexcept{
		if(ptr != upr.ptr){
			release();
			ptr = upr.ptr;
			del = upr.del;
			upr.ptr = nullptr;
			//upr.del = nullptr;
		}
		return *this;
	}
	~UniquePtr() noexcept{
		release();
	}
	T* get(){
		return ptr; 
	}
	T* operator->(){
		return ptr;
	}
	T& operator*(){
		return *ptr;
	}
	operator bool(){
		return ptr != nullptr;
	}
	void reset(T* p = nullptr) noexcept{
		release();
		ptr = p;
	}
};

void test(){
	/*
	UniquePtr<int> upr1(new int(1));
	UniquePtr<int> upr2(move(upr1));
	UniquePtr<int> upr3(new int(2));
	upr3 = move(upr2);
	*/
	UniquePtr<int, Deletor2> upr1(new int(1));
	UniquePtr<int, Deletor2> upr2(move(upr1));
	UniquePtr<int, Deletor2> upr3(new int(2));
	upr3 = move(upr2);
	cout << *upr3 << endl;
}

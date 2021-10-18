//
// Created by Kiven on 2021/10/12.
//

#ifndef LEETCODE_SINGLELINKLIST_H
#define LEETCODE_SINGLELINKLIST_H


#include <iostream>

using namespace std;

template <class T> class List;
template <class T> class Iterator;

//1. Node class(single link)
template <class T>
class Node
{
private:
    Node(const T & x): val(x), next(nullptr) {}
    T val;
    Node<T> * next;
    friend class List<T>;
    friend class Iterator<T>;
};

//2. Iterator class
template <class T>
class Iterator
{
public:
    using iterator = Iterator<T>;
    Iterator(Node<T>* node): cur(node) { }
    Iterator(const Iterator<T>& li): cur(li.cur) { }
    Iterator(): cur(nullptr) { }
    T& operator*(){
        return cur->val;
    };
    bool operator!=(const iterator & rhs) {
        return cur != rhs.cur;
    }
    iterator& operator++(){
        cur = cur -> next;
        return *this;
    }
    iterator operator++(int){
        auto res = *this;
        cur = cur->next;
        return res;
    }

private:
    Node<T> * cur;
};

//3. List class
template <class T>
class List
{
public:
    using iterator = Iterator<T>;
    List() : head(nullptr), last(nullptr), m_size(0){ };
    ~List(){
        Node<T> * p = head;
        while (p)
        {
            Node<T> * next = p->next;
            delete p;
            p = next;
        }
        m_size = 0;
    };

    void add(const T & x){
        Node<T> * newNode = new Node<T> (x);
        if (!head) head = last = newNode;
        else
        {
            last->next= newNode;
            last = newNode;
        }
        last->next = nullptr;  //the end state
        m_size++;
    }

    void erase(const T& x){

        if(head->val == x){
            Node<T>* tmp = head;
            head = head->next;
            tmp->next = nullptr;
            delete(tmp);
            m_size--;
            return;
        }

        Node<T>* p = head;
        while(p && p->next && p->next->val != x) p = p->next;
        if(!p->next) return; //didn't find
        Node<T>* tmp = p->next;
        p->next = p->next->next;
        tmp->next = nullptr;
        delete(tmp);
        m_size--;
    }

    iterator begin() const{
        return iterator(head);
    }
    iterator end() const{
        return iterator(nullptr);
    }
    unsigned size() const{
        return m_size;
    }

protected:
    Node<T> * head;
    Node<T> * last;
    unsigned m_size;
};

void testList(){
    List<int> ml;

    cout << "test empty list: " << endl;
    for(auto it = ml.begin(); it != ml.end(); it++) cout << *it << endl;
    cout << ml.size() << endl;

    ml.add(1);
    cout << "test one value" << endl;
    for(auto it = ml.begin(); it != ml.end(); it++) cout << *it << endl;
    cout << ml.size() << endl;

    ml.add(2);
    cout << "test two value" << endl;
    for(auto it = ml.begin(); it != ml.end(); it++) cout << *it << endl;
    cout << ml.size() << endl;

    ml.add(3);
    cout << "test three value" << endl;
    for(auto it = ml.begin(); it != ml.end(); it++) cout << *it << endl;
    cout << ml.size() << endl;

    ml.add(4);
    cout << "test four value" << endl;
    for(auto it = ml.begin(); it != ml.end(); it++) cout << *it << endl;
    cout << ml.size() << endl;

    //test ranged-based loop
    cout << "ranged-based loop" << endl;
    for(auto v : ml) cout << v << endl;
    cout << ml.size() << endl;

    cout << "test erase" << endl;
    ml.erase(5);
    for(auto v : ml) cout << v << endl;
    cout << ml.size() << endl;

    cout << "test erase" << endl;
    ml.erase(1);
    for(auto v : ml) cout << v << endl;
    cout << ml.size() << endl;

    cout << "test erase" << endl;
    ml.erase(3);
    for(auto v : ml) cout << v << endl;
    cout << ml.size() << endl;

    cout << "test erase" << endl;
    ml.erase(4);
    for(auto v : ml) cout << v << endl;
    cout << ml.size() << endl;

}

#endif //LEETCODE_SINGLELINKLIST_H

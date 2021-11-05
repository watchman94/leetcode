#include<unordered_map>
#include<memory>
#include<cassert>
using namespace std;

template<typename T1, typename T2 = T1>
class Node{
public:
	T1 key;
        T2 val;
	Node *prev, *next;
	explicit Node(T1 key = 0, T2 val = 0, Node *prev = nullptr, Node *next = nullptr):key(key), val(val), prev(prev), next(next){}
};


template<typename T1, typename T2 = T1>
class LRU_Cache{

	unordered_map<T1, Node<T1, T2>*> hash;
	Node<T1, T2> *head, *tail;
	unsigned _capacity;
	unsigned _size;

	void _update(Node<T1, T2>* tmp){
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}

	void _insert(Node<T1, T2>* tmp, T2 v){
		tmp->next = head->next;
		head->next->prev = tmp;
		head->next = tmp;
		tmp->prev = head;
		tmp->val = v;		
	}

	void _remove(){
		auto last = tail->prev;
		hash.erase(last->key);
		last->prev->next = tail;
		tail->prev = last->prev;
		delete(last);
	}


public: 
	explicit LRU_Cache(unsigned capacity = 0):_capacity(capacity), _size(0){
		head = new Node<T1, T2>();
		tail = new Node<T1, T2>();
		head->next = tail;
		tail->prev = head;
	}

	void put(T1 k, T2 v){
		if(hash.count(k)){
			auto tmp = hash[k];
			_update(tmp);
			_insert(tmp, v);
		}
		else{
			if(_size >= _capacity){
				_remove();
				_size--;
			}
			auto tmp = new Node<T1, T2>(k, v);
			hash[k] = tmp;
			_insert(tmp, v);
			_size++;
		}
	}

	T2 get(T1 k){
		if(!hash.count(k)) return -1;
		auto tmp = hash[k];
		_update(tmp);
		_insert(tmp, tmp->val);
		return tmp->val;
	}

	~LRU_Cache(){
		auto tmp = head;
		while(tmp){
			auto next = tmp->next;
			delete(tmp);
			tmp = next;
		}
	}
};

void test(){
	auto tmp = make_unique<LRU_Cache<int>>(2);
	tmp->put(1, 1);
	tmp->put(2, 2);
	assert(tmp->get(1) == 1);
	tmp->put(3, 3);
	assert(tmp->get(2) == -1);
	tmp->put(4, 4);
	assert(tmp->get(1) == -1);
	assert(tmp->get(3) == 3);
	assert(tmp->get(4) == 4);
}

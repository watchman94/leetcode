//
// Created by Kiven on 2021/10/11.
//

#ifndef LEETCODE_STOCKPRICE_2034_H
#include<unordered_map>
#include<set>
#include<cassert>
using namespace std;
class StockPrice {
public:
    unordered_map<int, int> ups;
    multiset<int> mps;
    int lastestT, lastestP;
    StockPrice(): lastestT(0){

    }

    void update(int timestamp, int price) {
        if(!ups.count(timestamp)){
            ups[timestamp] = price;
            mps.insert(price);
        }
        else{
            int tmp = ups[timestamp];
            mps.erase(mps.find(tmp));
            ups[timestamp] = price;
            mps.insert(price);
        }
        if(timestamp >= lastestT){
            lastestT = timestamp;
            lastestP = price;
        }
    }

    int current() {
        return lastestP;
    }

    int maximum() {
        return *rbegin(mps);
    }

    int minimum() {
        return *begin(mps);
    }

    void test(){
        update(1, 10);
        update(2, 5);
        assert(current() == 5);
        assert(maximum() == 10);
        update(1, 3);
        assert(maximum() == 5);
        update(4, 2);
        assert(minimum() == 2);
    }
};
#define LEETCODE_STOCKPRICE_2034_H

#endif //LEETCODE_STOCKPRICE_2034_H

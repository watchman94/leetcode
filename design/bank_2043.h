//
// Created by Kiven on 2021/10/20.
//

#ifndef LEETCODE_BANK_2043_H
#define LEETCODE_BANK_2043_H
#include<vector>
using namespace std;
class Bank {
public:
    using ll = long long;
    vector<ll> bal;
    Bank(vector<ll>& balance):bal(balance){}
    bool transfer(int a1, int a2, ll money){
        if(a1 < 1 || a1 > bal.size() || a2 < 1 || a2 > bal.size() || bal[a1 - 1] < money) return false;
        bal[a1 - 1] -= money;
        bal[a2 - 1] += money;
        return true;
    }
    bool deposit(int a, ll money){
        if(a < 1 || a > bal.size()) return false;
        bal[a - 1] += money;
        return true;
    }
    bool withdraw(int a, ll money){
        if(a < 1 || a > bal.size() || bal[a - 1] < money) return false;
        bal[a - 1] -= money;
        return true;

    }
};

#endif //LEETCODE_BANK_2043_H

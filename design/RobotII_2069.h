//
// Created by Kiven on 2021/11/14.
//

#ifndef LEETCODE_ROBOTII_2069_H
#define LEETCODE_ROBOTII_2069_H

#include<array>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Robot {
public:
    array<string, 4> _dirs = {"East", "North", "West", "South"};
    int _width, _height;
    int _cx = 0, _cy = 0, _cd = 0, _size = 0;
    unordered_map<int, int> hash1, hash2;
    Robot(int width, int height): _width(width), _height(height){
        for(int i = 0; i < _width; i++){
            hash1[i] = _size;
            hash2[_size++] = i;
        }
        for(int i = 1; i < _height; i++){
            hash1[i * _width + _width - 1] = _size;
            hash2[_size++] = i * _width + _width - 1;
        }
        for(int i = _width - 2; i >= 0; i--){
            hash1[(_height - 1) * _width + i] = _size;
            hash2[_size++] = (_height - 1) * _width + i;
        }
        for(int i = _height - 2; i > 0; i--){
            hash1[i * _width] = _size;
            hash2[_size++] = i * _width;
        }

    }

    void move(int num) {
        int t;
        if(_cd == 0 || _cd == 2){
            if(_cd == 0) {
                t = min(_width - 1 - _cy, num);
                _cy += t;
            }
            else{
                t = min(_cy, num);
                _cy -= t;
            }
            num -= t;
        }
        else{
            if(_cd == 1) {
                t = min(_height - 1 - _cx, num);
                _cx += t;
            }
            else{
                t = min(_cx, num);
                _cx -= t;
            }
            num -= t;
        }
        if(!num) return;

        num %= _size;
        int j = hash1[_cx * _width + _cy];
        t = min(_size - 1 - j, num);
        num -= t;
        j += t;
        j = (num + j) % _size;

        int tmp = hash2[j];
        _cx = tmp / _width;
        _cy = tmp % _width;
        if(_cx == 0) _cd = _cy == 0 ? 3 : 0;
        else if(_cx == _height - 1) _cd = _cy == _width - 1 ? 1 : 2;
        else if(_cy == 0) _cd = _cx == _height - 1 ? 2 : 3;
        else _cd = _cx == 0 ? 0 : 1;


    }

    vector<int> getPos() {
        return {_cy, _cx};
    }

    string getDir() {
        return _dirs[_cd];
    }
};

void robot_test(){
    /*
    Robot r(6,3);
    r.move(2);
    r.move(2);
    auto res = r.getPos();
    auto d = r.getDir();
    r.move(2);
    r.move(1);
    r.move(4);
    res = r.getPos();
    d = r.getDir();
    */
    /*
    Robot r(20,14);
    r.move(32);
    r.move(18);
    r.move(18);
    auto res = r.getPos();
    auto d = r.getDir();
    */

    Robot r(4,5);
    r.move(44);
    auto res = r.getPos();
    auto d = r.getDir();
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

#endif //LEETCODE_ROBOTII_2069_H

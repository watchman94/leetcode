//
// Created by Kiven on 2021/10/18.
//

#ifndef LEETCODE_WINNEROFGAME_2038_H
#define LEETCODE_WINNEROFGAME_2038_H

#include <string>
#include <string>
using namespace std;

class WinnerOfGame {
public:
    bool winnerOfGame(string str) {
        int a = 0, b = 0;
        str[0] == 'A' ? a++ : b++;
        int na = 0, nb = 0;
        for(int i = 1; i < str.size(); i++){
            if(str[i] == 'A'){
                if(str[i - 1] != 'A'){
                    b >= 3 ? nb += b - 2 : nb = nb;
                    b = 0;
                }
                a++;
            }
            else{
                if(str[i - 1] != 'B'){
                    a >= 3 ? na += a - 2 : na = na;
                    a = 0;
                }
                b++;
            }
        }
        a >= 3 ? na += a - 2 : na = na;
        b >= 3 ? nb += b - 2 : nb = nb;
        return na > nb;
    }

};

#endif //LEETCODE_WINNEROFGAME_2038_H

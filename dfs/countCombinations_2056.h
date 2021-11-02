//
// Created by Kiven on 2021/11/2.
//

#ifndef LEETCODE_COUNTCOMBINATIONS_2056_H
#define LEETCODE_COUNTCOMBINATIONS_2056_H

#include<vector>
#include<string>
using namespace std;

class CountCombinations {
public:

    int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},
                      {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int states[4][8][8] = {};
    int countCombinations(const vector<string>& pieces, const vector<vector<int>>& positions, int p = 0){
        if(p == pieces.size()) return 1;
        int x = positions[p][0] - 1, y = positions[p][1] - 1, res = 0;
        for(int i = 0; i < 8; i++){
            if((pieces[p] == "bishop" && i < 4) || (pieces[p] == "rook" && i >= 4))
                continue;
            int step = res == 0 ? 1 : 2;
            bool blocked = false;
            for(; !blocked; step++){
                int tx = x + (step - 1) * dirs[i][0];
                int ty = y + (step - 1) * dirs[i][1];
                if(min(tx, ty) < 0 || max(tx, ty) > 7) break;
                bool end = true;
                for(int tp = 0; tp < p; tp++){
                    end &= (states[tp][tx][ty] >= 0 && states[tp][tx][ty] < step);
                    blocked |= (states[tp][tx][ty] < 0 && -1 * states[tp][tx][ty] <= step) || states[tp][tx][ty] == step;
                }
                if(end){
                    states[p][tx][ty] = -1 * step;
                    res += countCombinations(pieces, positions, p + 1);
                }
                states[p][tx][ty] = step;

            }
            fill_n(states[p][0], 64, 0);
        }
        return res;
    }
};

#endif //LEETCODE_COUNTCOMBINATIONS_2056_H

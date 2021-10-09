class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < difficulty.size(); i++) vec.emplace_back(difficulty[i], profit[i]);
        sort(begin(vec), end(vec), [](const auto& a, const auto& b){return a.first < b.first;});
        map<int, int> hash;
        int tp = 0;
        for(const auto& [d, p] : vec){
            tp = max(p, tp);
            hash[d] = tp;
        }
        int res = 0;
        for(int i : worker){
            auto it = hash.upper_bound(i);
            if(it != begin(hash)){
                it--;
                res += it->second;
            }
        }
        return res;
    }
};
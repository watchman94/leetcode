class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(begin(ages), end(ages));
        int res = 0;
        for(int i = 0; i < ages.size(); i++){
            auto it1 = upper_bound(begin(ages), end(ages), ages[i]); //<=it1;
            it1--;
            double x = 0.5 * ages[i] + 7;
            auto it2 = upper_bound(begin(ages), end(ages), x); // >it2
            int d = it1 - it2;
            if(d <= 0) continue;
            if(ages[i] >= 100) res += d;
            else{
                auto it3 = upper_bound(begin(ages), end(ages), 100);
                it3--;
                int d1 = it3 - it2;
                res += min(d, max(0, d1));
            }

        }
        return res;
    }
};
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(begin(arr), end(arr));
        unordered_map<int, long long> hash;
        for(int i : arr) hash.emplace(i, 1);
        int n = arr.size();
        long long res = 0;
        const int mod = 1e9 + 7;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++){
                int a = arr[i], b = arr[j];
                if(a % b) continue;
                int c = a / b;
                long long tmp =  (hash[c] % mod) * (hash[b] % mod) % mod;
                hash[a] = (hash[a] + tmp) % mod;
            }
        for(auto& [i, n] : hash) res = (res + n) % mod;
        return res;
    }
};
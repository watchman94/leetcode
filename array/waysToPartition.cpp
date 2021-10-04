#include<vector>
#include<unordered_map>
using namespace std;


struct Solution{

	int waysToPartition(vector<int>& nums, int k){
		int n = nums.size();
		vector<long long> p(n, 0), s(n, 0);
		p[0] = nums[0], s[n - 1] = nums[n - 1];
		for(int i = 1; i < n; i++) p[i] = p[i - 1] + nums[i];
		for(int i = n - 2; i >= 0; i--) s[i] = s[i + 1] + nums[i];
		unordered_map<long long, int> right, left;
		for(int i = 0; i < n - 1; i++) right[p[i] - s[i + 1]]++;
		int res = right[0];
		for(int i = 0; i < n; i++){
			int d = k - nums[i], cur = 0;
			if(left.count(d)) cur += left[d];
			if(right.count(-1 * d)) cur += right[-1 * d];
			res = max(res, cur);
			if(i != n - 1){
				d = p[i] - s[i + 1];
				left[d]++; right[d]--;
				if(right[d] == 0) right.erase(d);
			}
		}
		return res;
	}

	
};





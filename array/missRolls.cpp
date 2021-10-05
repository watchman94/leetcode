#include<vector>
#include<numeric>
using namespace std;

struct Solution{
	vector<int> mRs(vector<int> rolls, int mean, int n){
		double sum = accumulate(begin(rolls), end(rolls), 0);
		double m = (mean * (n + rolls.size()) - sum) / n;
		if(m > 6 || m < 1) return {};
		vector<int> res;
		sum = (mean * (n + rolls.size()) - sum);
		int tn = n;
		for(int i = 0; i < n - 1; i++){
			int t = floor(sum / tn);
			res.push_back(t);
			sum -= t;
			tn--;
		}
		res.push_back(sum);
		return res;
	}
};
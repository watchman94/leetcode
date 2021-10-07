#include<string>
using namespace std;

class Solution{
	int minimumLengthEncoding(vector<string>& vec){
		auto cmp = [](const auto& a, const auto& b){return a.size() > b.size() || (a.size() == b.size() && a > b);};
		//auto cmp = [](const auto& a, const auto& b){return a.size() >= b.size();};
		set<string, decltype(cmp)> hash(begin(vec), end(vec), cmp);
		int res = 0;
		while(!hash.empty()){
			string str = *hash.begin();
			res += str.size() + 1;
			hash.erase(str);
			int n = str.size();
			for(int i = 1; i < n; i++){
				string s = str.substr(i, n - i);
				if(hash.count(s)) hash.erase(s);
			}
		}
		return res;
	}
};
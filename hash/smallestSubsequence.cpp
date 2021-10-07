#include<string>
using namespace std;

class Solution{
	int smallestGood(vector<int>& front, vector<int>& back){
		unordered_set<int> hash1;
		set<int> hash2;
		for(int i = 0; i < front.size(); i++){
			hash2.insert(front[i]);
			hash2.insert(back[i]);
			if(front[i] == back[i]) hash1.insert(front[i]);
		}
		for(int i : hash2)
			if(!hash1.count(i))
				return i;
		return 0;
	}
};
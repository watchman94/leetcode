#include<string>
using namespace std;

class Solution{
	string smallestSubsequence(string s, int k, char letter, int r){
		int n = s.size(), m = 0;
		for(char ch : s) m = ch == letter ? m + 1 : m;
		string st;
		int c = 0;
		for(int i = 0; i < n; i++){
			while(!st.empty() && st.back() > s[i] && n - i + st.size() > k && (st.back() != letter || m > r)){
				char ch = st.back();
				st.pop_back();
				if(ch == letter) r++;
			}
			if(st.size() < k){
				if(s[i] == letter){
					st.push_back(s[i]);
					r--;
				}
				else if(k - int(st.size()) > r) st.push_back(s[i]);
			}
			if(s[i] == letter) m--;
		}
		return st;
	}
};
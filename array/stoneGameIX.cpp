class Solution {
	public:
	bool stoneGameIX(vector<int>& stones) {
		vector<int> c(3, 0);
		for(int i : stones) c[i % 3]++;
		if(c[1] == 0) return c[2] > 2 && (c[0] % 2);
		if(c[2] == 0) return c[1] > 2 && (c[0] % 2);
		if(abs(c[1] - c[2]) > 2) return true;
		return !(c[0] % 2);
	}
};

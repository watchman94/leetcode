class NumSimilarGroups {
public:
    
    int find(int i, vector<int>& roots){
		return roots[i] == i ? i : roots[i] = find(roots[i], roots);
	}

    int numSimilarGroups(vector<string>& vec) {
        int n = vec.size();
		int m = vec[0].size();
		vector<int> roots(n, 0);
		iota(begin(roots), end(roots), 0);
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				int ri = find(i, roots);
				int rj = find(j, roots);
				if(ri == rj) continue;
				int k = 0; int cnt = 0;
				for(; k < m && cnt <= 2; k++) cnt += (vec[i][k] != vec[j][k]);
				if(k == m && cnt <= 2) roots[ri] = rj;
			}
		unordered_set<int> hash;
		for(int i = 0; i < n; i++) hash.insert(find(i, roots));
		return hash.size();
    }
};
class NumMagicSquaresInside {
public:
    int numMagicSquaresInside(vector<vector<int>>& vec) {
        int n = vec.size();
		int m = vec[0].size();
		int res = 0;
		for(int i = 0; i < n - 2; i++)
			for(int j = 0; j < m - 2; j++){
				unordered_set<int> hash;
				bool flag = true;
				int cs1 = 0, cs2 = 0, cs3 = 0;
				for(int p = 0; p < 3; p++){
					int sum = 0;
					for(int q = 0; q < 3; q++){
						if(vec[i + p][j + q] < 1 || vec[i + p][j + q] > 9){
							flag = false;
							break;
						}
						sum += vec[i + p][j + q];
						hash.insert(vec[i + p][j + q]);
						if(q == 0) cs1 += vec[i + p][j + q];
						else if(q == 1) cs2 += vec[i + p][j + q];
						else cs3 += vec[i + p][j + q];
					}
					if(sum != 15) flag = false;
					if(!flag) break;
				}
				if(!flag) continue;
				int ds1 = vec[i][j] + vec[i + 1][j + 1] + vec[i + 2][j + 2];
				int ds2 = vec[i][j + 2] + vec[i + 1][j + 1] + vec[i + 2][j];
				if(cs1 == 15 && cs2 == 15 && cs3 == 15 && ds1 == 15 && ds2 == 15 && hash.size() == 9) res++;	
			}
		return res;
    }
};

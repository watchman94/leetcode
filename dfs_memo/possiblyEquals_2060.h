class PossiblyEquals{
public:
    bool possiblyEquals(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
  	    vector<vector<vector<int>>> memo(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(2001, -1)));
        return dfs(s1, s2, 0, 0, 0, memo);
    }

 bool dfs(const string& s1, const string& s2, int i, int j, int d, vector<vector<vector<int>>>& memo){
      int n1 = s1.size(), n2 = s2.size();
      if(i == n1 && j == n2) return d == 0;
      if(memo[i][j][d + 1000] != -1) return memo[i][j][d + 1000];

      if(i < n1){
            if(isdigit(s1[i])){
                int cnt = 0, c = 0;
                while(c < 3 && i + c < n1 && isdigit(s1[i + c])){
                    cnt = cnt * 10 + (s1[i + c] - '0');
                    c++;
                    if(dfs(s1, s2, i + c, j, d - cnt, memo))
                        return memo[i][j][d + 1000] = true;
                }
            }
            else{
                if(d > 0 && dfs(s1, s2, i + 1, j, d - 1, memo))
                    return memo[i][j][d + 1000] = true;
                else if(d == 0 && j < n2 && s1[i] == s2[j])
                    return memo[i][j][d + 1000] = dfs(s1, s2, i + 1, j + 1, d, memo);
            }
      }
      if(j < n2){
            if(isdigit(s2[j])){
                int cnt = 0, c = 0;
                while(c < 3 && c + j < n2 && isdigit(s2[c + j])){
                    cnt = cnt * 10 + (s2[c + j] - '0');
                    c++;
                    if(dfs(s1, s2, i, j + c, d + cnt, memo))
                        return memo[i][j][d + 1000] = true;
                }
            }
            else if(d < 0 && dfs(s1, s2, i, j + 1, d + 1, memo))
                return memo[i][j][d + 1000] = true;
      }

      return memo[i][j][d + 1000] = false;
 
 }
};
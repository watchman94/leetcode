int nBI(const vector<vector<int>>& edges, const vector<int>& pat){
  int n = pat.size();
  vector<int> time(n, -1);
  time[0] = 0;
  vector<vector<int>> nei(n);
  for(auto& edge : edges){
   nei[edge[0]].push_back(edge[1]);
   nei[edge[1]].push_back(edge[0]);
  }
  queue<int> q;
  q.push(0);
  while(!q.empty()){
   auto tmp = q.front();
   q.pop();
   for(int i : nei[tmp]){
    if(time[i] == -1){
     time[i] = time[tmp] + 1;
     q.push(i);
    }
   }
  }
  int res = 0;
  for(int i = 1; i < n; i++){
   int num = (2 * time[i] - 1) / pat[i];
   int t0 = num * pat[i];
   int t = t0 + 2 * time[i];
   res = max(res, t);
  }
  return res + 1;
 }
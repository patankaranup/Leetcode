class Solution1 {
public:
    typedef long long LL;
    int bfs(int u, unordered_map<int, vector<int>> &adj ){
       unordered_set<int> visited;
       queue<int> que;
       que.push(u);
       visited.insert(u);
       while(!que.empty()){
           int curr = que.front();
           que.pop();
           for(auto &v : adj[curr]){
               if(visited.find(v) == visited.end()){
                   visited.insert(v);
                   que.push(v);
               }
           }
       }
       return visited.size();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) {
                    continue;
                }
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];

                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

                if(r1*r1 >= distance){
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;
        for(int i=0; i<n; i++){
            int count = bfs(i,adj);
            result = max(result,count);
        }
        return result;
    }
};
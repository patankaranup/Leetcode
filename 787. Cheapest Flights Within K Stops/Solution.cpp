class Solution {
public:
    typedef pair<int,int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        unordered_map<int, vector<P>> adj;
        for(auto &iter : flights){
            int u = iter[0];
            int v = iter[1];
            int w = iter[2];
            adj[u].push_back({v,w}); 
        }
        // dijkstra's algo 
        queue<P> que;
        que.push({src,0});
        int stops = 0;
        while(!que.empty() && stops<=k ){
            int n = que.size();
            while(n--){
                auto &curr = que.front();
                int u    = curr.first;
                int u_cost = curr.second;
                que.pop();

                for(auto &iter : adj[u]){
                    int v      = iter.first;
                    int v_cost = iter.second;
                    if(distance[v] > u_cost+v_cost){
                        distance[v] = u_cost+v_cost;
                        que.push({v,u_cost+v_cost});
                    }
                }
            }
            stops++;
        }
        if(distance[dst] == INT_MAX){
            return -1;
        }
        return distance[dst];
    }
};
class Solution {
public:
    typedef pair<int,int> P;
    int PrimsAlgo(vector<vector<P>> &adj, int n){
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});
        vector<bool>inMST(n,false);
        int sum = 0;

        while(!pq.empty()){
            auto elem = pq.top();
            pq.pop();
            int wt = elem.first;
            int node = elem.second;

            if(inMST[node]){
                continue;
            }

            inMST[node] = true;

            sum += wt;

            for(auto &temp : adj[node]){
                int v = temp.first;
                int v_wt = temp.second;
                if(inMST[v] == false){
                    pq.push({v_wt,v});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n); 

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                // distance 
                int dist = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        return PrimsAlgo(adj,n);
    }
};
class Solution {
public:
    // probability and node
    typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // graph
        unordered_map<int, vector<pair<int, double>>> adj;
        // result vector
        vector<double> result(n, 0);
        // making graph adj list
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]; // node 1 
            int v = edges[i][1]; // node 2
            double prob = succProb[i]; 
            // undirected graph
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        // max heap because we need maximum probability
        priority_queue<P> pq; 
		result[start] = 1;
		pq.push({1.0, start});

		while(!pq.empty()) {
		    int curnode = pq.top().second;
            double curProb = pq.top().first;
            pq.pop();

            for(auto &child : adj[curnode])
            {
                if(result[child.first] < curProb*child.second) //checking for maximum probability
                {
                    result[child.first] = curProb*child.second;
                    pq.push({result[child.first], child.first});
                }
            }
		}
		return result[end];
    }
};
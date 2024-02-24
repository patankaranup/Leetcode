class Solution2 {
public:
    // person2 and time 
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // making graph 
        // p1 -> {p2,t1}, {p3,t2} 
        unordered_map<int,vector<P>> adj;
        for(auto &it : meetings){
            int p1   = it[0];
            int p2   = it[1];
            int time = it[2];
            adj[p1].push_back({p2,time});
            adj[p2].push_back({p1,time});
        }
        vector<int> time_when_know_secret(n, INT_MAX);
        // queue for bfs 
        priority_queue<P, vector<P>, greater<P>> pq; 
        pq.push({0,0}); 
        pq.push({0,firstPerson});
        vector<bool> visited(n,false);

        while(!pq.empty()){
            P curr = pq.top();
            pq.pop();
            int curr_time = curr.first;
            int curr_person  = curr.second;
            if(visited[curr_person]) {
                continue;
            }
            visited[curr_person] = true;
            for(auto &iter : adj[curr_person]){
                int next_person = iter.first;
                int meet_time   = iter.second;
                // the next meeting time is greater than the meeting time of the curr_person
                if(meet_time >= curr_time && visited[next_person] == false){
                    time_when_know_secret[next_person] = true;
                    pq.push({meet_time,next_person}); 
                }
            }
        }
        vector<int> result;
        for(int i=0; i<n; i++){
            if(visited[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};
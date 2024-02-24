class Solution1 {
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
        queue<P> que;
        que.push({0,0});
        que.push({firstPerson,0});
        time_when_know_secret[0]           = 0;
        time_when_know_secret[firstPerson] = 0;

        while(!que.empty()){
            P curr = que.front();
            que.pop();
            int curr_person = curr.first;
            int curr_time   = curr.second;
            for(auto &iter : adj[curr_person]){
                int next_person = iter.first;
                int meet_time   = iter.second;
                // the next meeting time is greater than the meeting time of the curr_person
                if(meet_time >= curr_time && time_when_know_secret[next_person]>meet_time){
                    time_when_know_secret[next_person] = meet_time;
                    que.push({next_person,meet_time});
                }
            }
        }
        vector<int> result;
        for(int i=0; i<n; i++){
            if(time_when_know_secret[i] != INT_MAX){
                result.push_back(i);
            }
        }
        return result;
    }
};
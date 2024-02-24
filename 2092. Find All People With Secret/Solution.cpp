class Solution {
public:
    typedef pair<int,int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // time to meetings map 
        map<int, vector<P>> time_to_meetings;
        for(auto &meet : meetings){
            int p1 = meet[0];
            int p2 = meet[1];
            int time = meet[2];
            time_to_meetings[time].push_back({p1,p2});
        }

        // 0 and first person knows secret 
        vector<bool> know_secret(n,false);
        know_secret[0] = true;
        know_secret[firstPerson] = true; 

        for(auto &iter : time_to_meetings){
            int time = iter.first;
            vector<P> meets = iter.second;

            // now time to make graph 
            // p1 -> p2, p3, p4 
            unordered_map<int,vector<int>> adj;
            unordered_set<int> alreadyAdded;
            queue<int> que;

            for(auto &meet : meets){    
                int p1 = meet.first;
                int p2 = meet.second;
                adj[p1].push_back(p2);
                adj[p2].push_back(p1); 
                if(know_secret[p1] == true && alreadyAdded.find(p1) == alreadyAdded.end()){
                    que.push(p1);
                    alreadyAdded.insert(p1);
                }
                if(know_secret[p2] == true && alreadyAdded.find(p2) == alreadyAdded.end()){
                    que.push(p2);
                    alreadyAdded.insert(p2); 
                }
            }
            // now time to spread the secret to everybody connected to graph 
            while(!que.empty()){
                int curr_p = que.front();
                que.pop();
                for(int &next_p : adj[curr_p]){
                    if(know_secret[next_p] == false){
                        know_secret[next_p] = true;
                        que.push(next_p);
                    }
                }
            }
        }
        vector<int> result;
        for(int i=0; i<n; i++){
            if(know_secret[i]){
                result.push_back(i);
            } 
        }
        return result;
    }
};
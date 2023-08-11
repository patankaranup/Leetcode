class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);
        // number in arrays to index in which they are present 
        for(int i=0; i<n; i++){
            // number -> {(idx) 0,1,2,7,9}
            mp[arr[i]].push_back(i);
        }
        queue<int> que;
        que.push(0);
        visited[0] = true;

        int steps = 0;
         
        while(!que.empty()){
            int size = que.size();
            while(size--){
                int curr_idx = que.front();
                que.pop();
                // we reached the last idx
                if(curr_idx == n-1){
                    return steps;
                }
                // we can go to left right and the element which same 
                int left = curr_idx - 1;
                int right = curr_idx + 1;
                // put left in queue
                if(left>=0 && !visited[left]){
                    que.push(left);
                    visited[left] = true;
                }
                // put right in queue
                if(right<=n-1 && !visited[right]){
                    que.push(right);
                    visited[right] = true;
                }
                // now put all the index which have same value as of curr_idx
                int curr_element = arr[curr_idx];
                for(int &idx : mp[curr_element]){
                    if(!visited[idx]){
                        que.push(idx);
                        visited[idx] = true;
                    }
                }
                // this is the most important step after putting the idx of same element you need to erase it from map so that we cannot put it again in queue
                mp.erase(arr[curr_idx]);   
            }
            steps++;
        }
        return steps;
    }
};
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> que;
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '@'){
                    que.push({i,j,0,0});
                } else if(grid[i][j] >= 'a' && grid[i][j]<= 'f'){
                    count++;
                }
            }
        }

        int final_key_status_decimal = pow(2,count) - 1;
        int visited[m][n][final_key_status_decimal+1]; 
        memset(visited,0,sizeof(visited));

        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            int i = temp[0];
            int j = temp[1];
            int steps = temp[2];
            int curr_key_status_decimal = temp[3];

            if(curr_key_status_decimal == final_key_status_decimal){
                return steps;
            }
            for(auto &dir : directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];
                if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j] != '#'){
                    char ch = grid[new_i][new_j];
                    if(ch>='A' && ch<='F'){ // for lock 
                        if(visited[new_i][new_j][curr_key_status_decimal] == 0 && ((curr_key_status_decimal >> (ch-'A')) & 1) == 1){
                            // we have the key for this lock
                            visited[new_i][new_j][curr_key_status_decimal] = 1;
                            que.push({new_i,new_j,steps+1,curr_key_status_decimal});    
                        }
                    } else if(ch>='a' && ch<='f'){ // for key
                        int new_key_status_decimal = curr_key_status_decimal | (1 << (ch-'a'));
                        if(visited[new_i][new_j][new_key_status_decimal] == 0){
                            visited[new_i][new_j][new_key_status_decimal] = 1;
                            que.push({new_i,new_j,steps+1,new_key_status_decimal});    
                        }
                    } else{
                        // for dot
                        if(visited[new_i][new_j][curr_key_status_decimal] == 0){
                            visited[new_i][new_j][curr_key_status_decimal] = 1;
                            que.push({new_i,new_j,steps+1,curr_key_status_decimal});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
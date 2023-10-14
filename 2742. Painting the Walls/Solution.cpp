class Solution {
public:
    typedef long long ll;
    int n;
    ll memo[501][501];
    ll solve(vector<int>& cost, vector<int>& time, int idx, int remaining_walls){
        if(remaining_walls<=0){
            return 0;
        }
        if(idx >= n){
            return 1e9;
        }
        if(memo[idx][remaining_walls] != -1){
            return memo[idx][remaining_walls];
        }
        int new_remaining_walls = remaining_walls - 1 - time[idx];
        ll paint_wall = cost[idx] + solve(cost,time,idx+1,new_remaining_walls);
        ll skip_wall = solve(cost,time,idx+1,remaining_walls);
        return memo[idx][remaining_walls] = min(paint_wall,skip_wall);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        memset(memo,-1,sizeof(memo));
        return solve(cost,time,0,n);
    }
};
class Solution {
public:
    int n;
    int memo[2001][2001];
    unordered_map<int,int> mp;
    int solve(int curr_stone_idx, int prev_jump, vector<int>& stones){
        // base case
        if(curr_stone_idx == n-1){
            return true;
        }
        if(memo[curr_stone_idx][prev_jump] != -1){
            return memo[curr_stone_idx][prev_jump];
        }
        bool result = false;

        int curr_stone = stones[curr_stone_idx];   

        // we can use for loop for k-1 units k and k+1 units
        for(int next_jump = prev_jump-1; next_jump<=prev_jump+1; next_jump++){

            if(next_jump>0){

                int next_stone = curr_stone+next_jump;

                if(mp.find(next_stone) != mp.end()){

                    result = result || solve(mp[next_stone],next_jump,stones);

                }

            }

        }

        return memo[curr_stone_idx][prev_jump] = result;
    }
    bool canCross(vector<int>& stones) {

        n = stones.size();
        memset(memo,-1,sizeof(memo));
        if(stones[1] != 1){
            return false;
        }
        
        for(int i=0; i<n; i++){
            int stone_unit = stones[i];
            mp[stones[i]] = i;
        }
        return solve(mp[0],0,stones);
    }
};
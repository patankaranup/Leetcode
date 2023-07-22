class Solution {
public:
    unordered_map<string,double> mp;
    int N;
    vector<pair<int,int>> directions = {
        {-2,1},{-1,2},{1,2},{2,1},
        {2,-1},{1,-2},{-1,-2},{-2,-1}
    };
    double solve(int row, int column, int k){
        if(row<0 || row>=N || column<0 || column>=N){
            return 0;
        }
        if(k==0){
            // one possibility done return 1
            return 1;
        }

        string key = to_string(k) + "_" + to_string(row) + "_" + to_string(column);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }

        double ans = 0;
        for(auto &dir : directions){
            int new_row = row + dir.first;
            int new_col = column + dir.second;
            ans += (double)solve(new_row,new_col,k-1);
        }
        return mp[key] = (double)(ans/(8.0));
    };
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        return solve(row,column,k);
    };
};
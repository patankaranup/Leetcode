class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> directions {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1}, {0, 0}, {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        vector<vector<int>> res(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cnt = 0;
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if (0 <= new_i && 0 <= new_j && new_i < m  && new_j < n) {
                        sum += img[new_i][new_j];
                        cnt += 1;
                    }
                }
                res[i][j] = sum/cnt;
            }
        }
        return res;
    }
};
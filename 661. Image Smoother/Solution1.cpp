class Solution1 {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<int> arr_n(n);
        int pc = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cnt = 0;
                // Right neighbor
                if (j + 1 < n) {
                    sum += img[i][j + 1];
                    cnt += 1;
                }
                // Down neighbors
                if (i + 1 < m) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1];
                        cnt += 1;
                    }
                    sum += img[i + 1][j];
                    cnt += 1;
                    if (j + 1 < n) {
                        sum += img[i + 1][j + 1];
                        cnt += 1;
                    }
                }
                // Left neighbor
                if (j - 1 >= 0) {
                    sum += arr_n[j - 1];
                    cnt += 1;
                }
                // Upper neighbors
                if (i - 1 >= 0) {
                    // Left-top corner neighbor.
                    if (j - 1 >=  0) {
                        sum += pc;
                        cnt += 1;
                    }
                    // Top edge neighbor.
                    sum += arr_n[j];
                    cnt += 1;
                    // Right-top cornerneighbor.
                    if (j + 1 < n) {
                        sum += arr_n[j + 1];
                        cnt += 1;
                    }
                }
                // Current cell 
                sum += img[i][j];
                cnt += 1;
                // store corner value
                if (i - 1 >= 0) {
                    pc = arr_n[j];
                }
                // Storing the curr value
                arr_n[j] = img[i][j];
                img[i][j] = sum / cnt;
            }
        }
        return img;
    }
};
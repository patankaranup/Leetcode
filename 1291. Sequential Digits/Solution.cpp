class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i = 1; i <= 8; i++) {
            que.push(i);
        }
        vector<int> ans;
        while(!que.empty()) {
            int temp = que.front();
            que.pop();
            if(temp >= low && temp <= high) {
                ans.push_back(temp);
            }
            int last_digit = temp%10;
            if(last_digit + 1 <= 9) {
                que.push(temp * 10 +(last_digit + 1));
            }
        }
        return ans;
    }
};
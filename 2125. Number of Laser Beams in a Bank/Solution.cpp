class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int res = 0;
        int prev = 0;
        for(int i=0; i<n; i++){
            int curr_cnt = 0;
            for(auto &ch : bank[i]){
                if(ch == '1'){
                    curr_cnt++;
                }
            }
            if(prev && curr_cnt){
                res = res+(prev*curr_cnt);
            } 
            if(curr_cnt != 0){
                prev = curr_cnt;
            }
        }
        return res;
    }
};
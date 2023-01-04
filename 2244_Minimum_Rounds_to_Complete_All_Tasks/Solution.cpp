class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int > mp;
        for (int &task : tasks){
            mp[task] +=1;
        }
        int round = 0;
        for (auto &it : mp){
            int count = it.second;
            if (count == 1){
                return -1;
            } else if (count % 3 == 0){
                round += count/3;
            } else {
                round += (count/3)+1;
            }
        }
        return round;
    }
};

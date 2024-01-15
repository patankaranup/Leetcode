class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // palyer to freq of losses 
        unordered_map<int,int> mp;
        for(auto &iter : matches){
            int loser = iter[1];
            mp[loser]++;
        }

        vector<int> wonAll;
        vector<int> losedOne;

        for(int i=0; i<matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];
            if(mp.find(winner) == mp.end()) {
                wonAll.push_back(winner); 
                mp[winner]++;
            }
            if(mp[loser] == 1){
                losedOne.push_back(loser);
            }
            
        }
        sort(begin(wonAll),end(wonAll));
        sort(begin(losedOne),end(losedOne));
        return {wonAll, losedOne};
    }
};
class Solution1 {
public:
    int binary_Search_Lower_Bound(int l, int r, vector<int>& potions, int minPotion){
        int possibeIndex = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(potions[mid]>=minPotion){
                possibeIndex = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return possibeIndex;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        
        int n = potions.size();
        
        sort(begin(potions), end(potions));
        
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        
        for(int i = 0; i<m; i++) {
            
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);
            
            if(minPotion > maxPotion) {
                answer.push_back(0);
                continue;
            }
            
            int index = binary_Search_Lower_Bound(0,n-1,potions,minPotion);
            
            answer.push_back(n-index);
            
        }
        
        return answer;
    }
};
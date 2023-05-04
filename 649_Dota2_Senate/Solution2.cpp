class Solution2 {
public:
    string predictPartyVictory(string senate) {
        
        int n = senate.length();
        
        queue<int> queR;
        queue<int> queD;
        
        for(int i = 0; i<n; i++) {
            if(senate[i] == 'R')
                queR.push(i);
            else
                queD.push(i);
        }
        
        while(!queR.empty() && !queD.empty()) {
            
            int R_idx = queR.front(); queR.pop();
            int D_idx = queD.front(); queD.pop();
            
            if(R_idx < D_idx) {
                queR.push(R_idx+n);
                
            } else {
                queD.push(D_idx+n);
                
            }
            
        }
        
        return queR.empty() ? "Dire" : "Radiant";
        
    }
};
class Solution {
public:
    bool checkRecord(string s) {

        int absent = 0;


        for(int i = 0; i<s.size(); i++){
            if (s[i]=='A'){
                absent++;
            } else if(s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L' ){
                return false;
            }
        }
        if (absent>=2){
            return false;
        }
        return true;
        
    }
};

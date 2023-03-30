class Solution {
public:
    unordered_map<string,bool> mp;
    bool recursion(string s1, string s2){
        if(s1 == s2){
            return true;
        }
        if(s1.length() != s2.length()){
            return false;
        }   
        string key = s1+"_"+s2;
        if(mp.find(key) != mp.end()){
            return mp[key];
        }

        bool result = false;
        int n = s1.length();
        for(int i=1; i<n; i++){
            // "great" , "eatgr"
            // i=2
            // swapped
            // s1.substr(0,i) "gr" = s2.substr(n-i,i) = "gr"
            // s1.substr(i,n-i) "eat" = s2.substr(0,n-i) = "eat"

            bool swapped = recursion(s1.substr(0,i),s2.substr(n-i,i)) && recursion(s1.substr(i,n-i),s2.substr(0,n-i));
            if(swapped){
                result =  true;
                break;
            }
            // "great" , "eatgr"
            // i=2
            // swapped
            // s1.substr(0,i) "gr" = s2.substr(0,i) = "ea"
            // s1.substr(i,n-i) "eat" = s2.substr(i,n-i) = "tgr"
            bool not_swapped = recursion(s1.substr(0,i),s2.substr(0,i)) && recursion(s1.substr(i,n-i),s2.substr(i,n-i));
            if(not_swapped){
                result = true;
                break;
            }
            
        }
        return mp[key] = result;
    }
    bool isScramble(string s1, string s2) {
        mp.clear();
        return recursion(s1,s2);
    }
};
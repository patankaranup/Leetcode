class Solution1 {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int maxV = 0;
        int count = 0;
        auto isVowel = [&](char ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };
        while(j<n){
            if(isVowel(s[j])){
                count++;
            } 
            if(j - i + 1 == k){
                maxV = max(count,maxV);
                if(isVowel(s[i])){
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxV;
    }
};
#include<bits/stdc++.h>
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(m != n) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0; i<n; i++){
            char ch1 = word1[i];
            char ch2 = word2[i];
            freq1[ch1-'a']++;
            freq2[ch2-'a']++;
        }

        // charaters should be present in both the frequencies 
        for(int i=0; i<26; i++) {
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            if(freq1[i] == 0 && freq2[i] == 0) continue;
            return false;
        }
        // both the frequency should be same that is match the frequency 
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));

        return freq1 == freq2;
    }
};
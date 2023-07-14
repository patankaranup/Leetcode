class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // element to size of subsequence
        unordered_map<int,int> mp;
        int result = 0;
        for(int i=0; i<n; i++){
            // previos val and currVal 
            int currVal = arr[i];
            int prevVal = currVal - difference;
            // len of prevVal and currVal
            int prevLen = mp[prevVal];
            int currLen = 1 + prevLen;
            // set currentval len
            mp[currVal] = currLen;

            // update the result
            result = max(result,currLen);

        }
        return result;
    }
};
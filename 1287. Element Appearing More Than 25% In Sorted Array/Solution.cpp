class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int f = (n/4);
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>f){
                return arr[i];
            }
        }
        return -1;
    }
};
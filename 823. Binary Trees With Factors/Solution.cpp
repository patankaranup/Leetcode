class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;
        for(int i=1; i<n; i++){
            int root = arr[i];
            mp[root] = 1;
            for(int j=0; j<i; j++){
                int lc = arr[j];
                if(root%lc == 0 && mp.find(arr[i]/lc) != mp.end()){
                    mp[root] += mp[lc]*mp[arr[i]/lc];
                }
            }
        }
        long long result = 0;
        for(auto &it : mp){
            result = (result + it.second)%MOD;
        }
        return result;
    }
};
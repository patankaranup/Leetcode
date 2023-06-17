class Solution {
public:
    map<pair<int,int>,int> mp;
    int solve(int idx,vector<int>& arr1, vector<int>& arr2,int prev){
        if(idx>=arr1.size()){
            return 0;
        }
        if(mp.find({idx,prev}) != mp.end()){
            return mp[{idx,prev}];
        }
        int result1 = 1e9+1;
        if(arr1[idx]>prev){ // we can skip
            result1 = solve(idx+1,arr1,arr2,arr1[idx]); // no operation here
        } 
        int result2 = 1e9+1;
        auto it = upper_bound(begin(arr2),end(arr2),prev);
        if(it!=end(arr2)){
            int j = it - begin(arr2);
            result2 = 1 + solve(idx+1,arr1,arr2,arr2[j]);
        }
        return mp[{idx,prev}] = min(result1,result2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        mp.clear();
        sort(begin(arr2),end(arr2));
        int result = solve(0, arr1, arr2, INT_MIN);
        if(result == 1e9+1){
            return -1;
        }
        return result;
    }
};

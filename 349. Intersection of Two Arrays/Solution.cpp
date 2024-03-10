class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(begin(nums1),end(nums1));
        vector<int> res;
        for(auto &num : nums2){
            if(st1.find(num) != st1.end()){
                res.push_back(num);
                st1.erase(num);
            }
        }
        return res;
    }
};
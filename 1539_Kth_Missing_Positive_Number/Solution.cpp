class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int num = 1;
        int i=0;
        while(i<n && k>0){
            if(arr[i] == num){
                // not missing 
                i++;
            } else {
                // missing 
                k--;
            }
            num++; 
        }
        // if k is still not equal to zero 
        while(k--){
            num++;
        }
        return num - 1;
    }
};
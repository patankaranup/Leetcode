class Solution1 {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int f = (n/4);
        for(int i=0; i<n-f; i++){
            int curr = arr[i];
            int last = arr[i+f];
            if(curr == last){
                return curr;
            }
        }
        return -1;
    }
};
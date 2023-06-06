class Solution1 {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> st(begin(arr),end(arr));

        int min_elem = *min_element(begin(arr),end(arr));
        int max_elem = *max_element(begin(arr),end(arr));
        if((max_elem-min_elem) % (n-1)!= 0 ){
            return false;
        }
        int d = (max_elem - min_elem)/(n-1);
        int i = 0;
        while(i<n){
            int num = min_elem + i*d;
            if(st.find(num) == st.end()){
                return false;
            }
            i++;
        }
        return true;
    }
};

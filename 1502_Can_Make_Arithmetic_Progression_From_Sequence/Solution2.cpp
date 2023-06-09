class Solution2 {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        
        int n = arr.size();

        int min_el = *min_element(begin(arr), end(arr)); //a0
        int max_el = *max_element(begin(arr), end(arr)); //a0+(n-1)*d
        
        if((max_el - min_el)%(n-1) != 0)
            return false;
        
        int d = (max_el - min_el)/(n-1);
        
        int i = 0;
        while (i < n) {
            if(arr[i] == min_el + i*d) {
                i++;
            } else {
                
                if((arr[i] - min_el) % d != 0)
                    return false;
                
                int j = (arr[i] - min_el)/d;
                
                if(arr[i] == arr[j])
                    return false;
                swap(arr[i], arr[j]);       
            }
        }        
        return true;
    }
};

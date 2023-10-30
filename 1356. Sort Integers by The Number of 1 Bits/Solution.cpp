class Solution {
public:
    int countOneBits(int num){
        int cnt = 0;
        while(num != 0){
            cnt += num&1;
            num>>=1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a, int &b){
            int count_a = countOneBits(a);
            int count_b = countOneBits(b);

            if(count_a == count_b){
                return a<b;
            }
            return count_a<count_b;
        };
        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};
class Solution1 {
public:
    char findTheDifference(string s, string t) {
        int sum_of_s = 0;
        for(char &ch : s){
            sum_of_s += ch;
        }
        int sum_of_t = 0;
        for(char &ch : t){
            sum_of_t += ch;
        }
        return (char)(sum_of_t-sum_of_s);
    }
};
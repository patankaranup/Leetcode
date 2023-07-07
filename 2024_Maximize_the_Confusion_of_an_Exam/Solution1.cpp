class Solution1 {
public:
    int result = 0;
    int n;
    void findMax(string &answerKey){
        int len = 0;
        int i = 0;
        while(i<n){
            if(answerKey[i] == 'T'){
                len = 1;
                i++;
                while(i<n && answerKey[i] == 'T'){
                    len++;
                    i++;
                }
                result = max(result,len);
            } else {
                len = 1;
                i++;
                while(i<n && answerKey[i] == 'F'){
                    len++;
                    i++;
                }
                result = max(result,len);
            }
        }
    }
    void solve(int idx, string &answerKey, int k){
        findMax(answerKey);

        if(idx>=n || k<=0){
            return;
        }
        // fliping the idx
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; 
        solve(idx+1,answerKey,k-1);

        // flipping back the idx
        answerKey[idx] = answerKey[idx] == 'T' ? 'F' : 'T'; 
        solve(idx+1,answerKey,k);

    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.length();
        solve(0,answerKey,k);
        return result;
    }
};
class Solution1 {
public:
    // time complexity nCk (nCr)
    vector<vector<int>> result;
    void solveCombinations(int start,int &n,int k,vector<int> &temp) {
        // we have got k elements in temp
        if(k==0){
            result.push_back(temp);
            return;
        }
        
        // using for loop 
        for(int i=start; i<=n; i++){
            // take start explore all possibilities 
            temp.push_back(i);
            solveCombinations(i+1,n,k-1,temp);
            // reject start 
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solveCombinations(1,n,k,temp);
        return result;    
    }
};
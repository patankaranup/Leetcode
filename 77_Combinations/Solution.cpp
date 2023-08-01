class Solution {
public:
    // time complexity nCk (nCr)
    vector<vector<int>> result;
    void solveCombinations(int start,int &n,int k,vector<int> &temp) {
        // we have got k elements in temp
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(start>n){
            return;
        }
        // take start explore all possibilities 
        temp.push_back(start);
        solveCombinations(start+1,n,k-1,temp);

        // reject start and exxplore all possibilities
        temp.pop_back();
        solveCombinations(start+1,n,k,temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solveCombinations(1,n,k,temp);
        return result;    
    }
};
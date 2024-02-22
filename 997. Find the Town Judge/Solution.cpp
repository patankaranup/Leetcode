class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n+1);
        vector<int> outDegree(n+1);

        for(auto &vec : trust){
            int u = vec[0];
            int v = vec[1];
            inDegree[v]++;
            outDegree[u]++;
        }
        for(int i=1; i<=n; i++){
            if(inDegree[i] == n-1 && outDegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
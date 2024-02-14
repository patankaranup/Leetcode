class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();
        vector<int> pos;
        vector<int> neg;
  
        // Segregate the array into positives and negatives.
        for(int i=0;i<n;i++){
      
            if(A[i]>0) pos.push_back(A[i]);
            else neg.push_back(A[i]);
        }
  
        // Positives on even indices, negatives on odd.
        for(int i=0;i<n/2;i++){
      
             A[2*i] = pos[i];
            A[2*i+1] = neg[i];
        }
  
  
        return A;
    }
};
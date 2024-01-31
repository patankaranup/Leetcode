class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            // if stack has smaller element at top remove it 
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            // if stack is empty the answer will be 0 
            if(st.empty()){
                ans[i] = 0;
            } else {
                // ans is difference of idx 
                ans[i] = st.top() - i;
            }
            // put the element to the stack 
            st.push(i);
        }
        return ans;
    }
};
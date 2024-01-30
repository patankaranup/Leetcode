class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> st;
        int i = 0;
        int n = tokens.size();
        while(i<n){
            if(tokens[i] == "+") {
                int elem1 = st.top();
                st.pop();
                int elem2 = st.top();
                st.pop();
                int val = elem2 + elem1;
                st.push(val);
            } else if(tokens[i] == "-") {
                int elem1 = st.top();
                st.pop();
                int elem2 = st.top();
                st.pop();
                int val = elem2 - elem1;
                st.push(val);
            } else if(tokens[i] == "*") {
                int elem1 = st.top();
                st.pop();
                int elem2 = st.top();
                st.pop();
                int val = elem1 * elem2;
                st.push(val);
            } else if(tokens[i] == "/") {
                int elem1 = st.top();
                st.pop();
                int elem2 = st.top();
                st.pop();
                int val = elem2 / elem1;
                st.push(val);
            } else {
                int val = stoi(tokens[i]);
                st.push(val);
            }
            i++;
        }
        return st.top();
    }
};
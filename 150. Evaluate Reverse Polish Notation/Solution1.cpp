class Solution1 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int a, int b) {return a+b;}},
            {"-", [](int a, int b) {return a-b;}},
            {"*", [](int a, int b) {return a*b;}},
            {"/", [](int a, int b) {return a/b;}}
        };
        for(string &s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int elem2 = st.top();
                st.pop();
                int elem1 = st.top();
                st.pop();
                int result = mp[s](elem1, elem2);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
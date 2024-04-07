class Solution2 {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> open_brackets;
        stack<int> asterisk;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                open_brackets.push(i);
            }else if(s[i] == '*'){
                asterisk.push(i);
            }else{
                if(!open_brackets.empty()){
                    open_brackets.pop();
                }else if(!asterisk.empty()){
                    asterisk.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open_brackets.empty() && !asterisk.empty()){
            if(open_brackets.top() > asterisk.top()){
                return false;
            }
            open_brackets.pop();
            asterisk.pop();
        }
        return open_brackets.empty();
    }
};
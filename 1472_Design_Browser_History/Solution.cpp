class BrowserHistory {
public:
    stack<string> curr;
    stack<string> fwd;
    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
        while(!fwd.empty()){
            fwd.pop();
        }
        curr.push(url);
    }
    
    string back(int steps) {
        string lastPage = "";
        while(steps-- && curr.size()>1){
            lastPage = curr.top();
            curr.pop();
            fwd.push(lastPage);
        }
        lastPage = curr.top();
        return lastPage;
    }
    
    string forward(int steps) {
        string page = "";
        while(steps-- && !fwd.empty()){
            page = fwd.top();
            fwd.pop();
            curr.push(page);
        }
        return curr.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

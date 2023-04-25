class SmallestInfiniteSet {
public:
    int curSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {
        curSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        if(!pq.empty()){
            result = pq.top();
            pq.pop();
            st.erase(result);
        } else {
            result = curSmallest;
            curSmallest += 1;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num >= curSmallest || st.find(num) != st.end()){
            return ;
        }
        st.insert(num);
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
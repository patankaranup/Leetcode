class SmallestInfiniteSet1 {
public:
    int curSmallest;
    set<int> st;
    SmallestInfiniteSet() {
        curSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        if(!st.empty()){
            result = *st.begin();
            st.erase(st.begin());
        } else {
            result = curSmallest;
            curSmallest += 1;
        }
        return result;
    }
    
    void addBack(int num) {
        if(num>=curSmallest || st.find(num) != st.end()){
            return ;
        }
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
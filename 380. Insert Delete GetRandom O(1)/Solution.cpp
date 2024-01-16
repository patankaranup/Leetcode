class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        // didnt find val return false 
        if(mp.find(val) == mp.end()) return false;
        // get the idx of the val since we want to remove it in O(1)
        int idx = mp[val];
        // put the last element in its place so no need to shift the whole vector
        int lastElement = vec.back();
        vec.back() = val;
        // put the last element at the position from where the val was removed 
        vec[idx] = lastElement;
        // update the last elements idx 
        mp[lastElement] = idx;
        // remove the val which is now at back and erase its entry from the map
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = vec.size();
        // this will return the integer number raning from 0 to n
        int idx = rand()%n;
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class MyHashMap {
public:
    vector<list<pair<int,int>>> vectorBuckets;
    int size = 1e4;
    MyHashMap() {
        vectorBuckets.resize(size);
    }
    void put(int key, int value) {
        int bucketNum = key%size;
        auto &chain = vectorBuckets[bucketNum];
        for (auto &iter : chain){
            if(iter.first == key){
                iter.second = value;
                return;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        int bucketNum = key%size;
        auto &chain = vectorBuckets[bucketNum];
        if(chain.empty()){
            return -1;
        }
        for(auto &iter : chain){
            if(iter.first == key){
                return iter.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketNum = key%size;
        auto &chain = vectorBuckets[bucketNum];
        for(auto iter = chain.begin(); iter != chain.end(); iter++){
            if(iter -> first == key){
                chain.erase(iter);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
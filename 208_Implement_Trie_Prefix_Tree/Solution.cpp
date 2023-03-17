class Trie {
public:
    // implementation of trie node
    struct TrieNode {
        bool endOfWorld;
        TrieNode* child[26];
    };

    TrieNode* createNode(){
        TrieNode* newNode = new TrieNode();
        newNode->endOfWorld = false;
        for(int i=0; i<26; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;

    Trie() {
        root = createNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(crawler->child[index] == NULL){
                crawler->child[index] = createNode();
            }
            crawler = crawler->child[index];
        }
        crawler->endOfWorld = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(crawler->child[index] == NULL){
                return false;
            }
            crawler = crawler->child[index];
        }
        if(crawler != NULL && crawler->endOfWorld == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        int i = 0;
        for(; i<prefix.length(); i++){
            char ch = prefix[i];
            int index = ch - 'a';
            if(crawler->child[index] == NULL){
                return false;
            }
            crawler = crawler->child[index];
        }
        if(i==prefix.length()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class WordDictionary {
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

    WordDictionary() {
        root = createNode();
    }
    
    void addWord(string word) {
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
    bool searchHelper(TrieNode* root, string word){
        TrieNode *crawler = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(ch == '.'){
                for(int j=0; j<26; j++){
                    if(crawler->child[j] != NULL){
                        if(searchHelper(crawler->child[j], word.substr(i+1)) == true){
                            return true;
                        }
                    }
                }
                return false;
            }
            else if (crawler->child[ch-'a'] == NULL){
                return false;
            }
            crawler = crawler->child[ch-'a'];
        }
        return (crawler != NULL && crawler->endOfWorld == true) ;

    }
    bool search(string word) {
        return searchHelper(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution2 {
public:
    unordered_map<Node*, Node*> mp;
    void bfs(queue<Node*> &q){
        while(!q.empty()){
            Node * node = q.front();
            Node * clone_node = mp[node];
            q.pop(); 
            for(Node * n : node->neighbors){
            if(mp.find(n) == mp.end()){
                Node * clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                q.push(n);
            } else {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        mp.clear();
        // clone of the given node 
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        // now clone its neighbor and its neighbor recursively
        queue<Node*> q;
        q.push(node);
        bfs(q);
        return clone_node;
    }
};
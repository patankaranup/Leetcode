class Solution {
public:
    int result;

    int dfs(unordered_map<int, vector<int>> &adj, int curr, int parent, string &s){
        int longest = 0;
        int second_longest = 0;

        for (int &child : adj[curr]){
            if (child == parent){
                continue;
            }
            int child_longest_length = dfs(adj, child, curr, s);
            // continue if adjacent characters equal
            if (s[child]==s[curr]){
                continue;
            }
            if (child_longest_length > second_longest){
                second_longest = child_longest_length;
            }
            if (second_longest > longest){
                swap(longest, second_longest);
            }
        }   

        int any_one = max(longest,second_longest)+1;
        int only_root = 1;
        int sub_tree = 1+longest+second_longest;
        result = max({result,any_one,only_root,sub_tree});


        return max(any_one, only_root);
    }

    int longestPath(vector<int>& parent, string s) {
        int n  = parent.size();
        unordered_map<int, vector<int>> adj;

        result = 0;
        // making a graph
        for (int i = 1; i<n; i++){
            int u = i;
            int v = parent[i];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        dfs(adj, 0 , -1, s);

        return result;
        
    }
};

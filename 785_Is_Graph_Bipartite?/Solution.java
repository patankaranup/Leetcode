class Solution {
    
    private boolean checkBipartiteDFS(int[][] adj, int u, int[] color, int currColor) {
        
        color[u] = currColor;
        
        for(int v : adj[u]) {
            if(color[v] == color[u]){
                return false;
            }
            if(color[v] == -1) {
                if(!checkBipartiteDFS(adj,v,color, 1-currColor)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    public boolean isBipartite(int[][] adj) {
        
        int n = adj.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);
        
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                if(!checkBipartiteDFS(adj,i,color,1)){
                    return false;
                }     
            }
        }
        return true;
    }
}


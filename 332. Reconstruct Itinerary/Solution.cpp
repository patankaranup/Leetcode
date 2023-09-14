class Solution {
public:
    int n;
    unordered_map<string, vector<string>> adj;
    vector<string> result;

    bool DFS(string fromCity, vector<string> &path){
        path.push_back(fromCity);
        if(path.size() == n+1){
            result = path;
            return true;
        }
        vector<string> &neighborCities = adj[fromCity];
        for(int i=0; i<neighborCities.size(); i++){
            string toCity = neighborCities[i];
            // remove to avoid cycle for now 
            neighborCities.erase(neighborCities.begin()+i);
            if(DFS(toCity,path)){
                return true;
            }
            neighborCities.insert(neighborCities.begin()+i,toCity);
        }
        path.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size();
        // making graph
        for(auto &ticket : tickets){
            adj[ticket[0]].push_back(ticket[1]);
        }
        // time to sort for lexical order 
        for (auto &edge : adj){
            sort(begin(edge.second),end(edge.second));
        }
        vector<string> path;
        DFS("JFK",path);
        return result;
    }
};
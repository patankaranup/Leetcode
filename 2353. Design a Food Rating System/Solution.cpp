class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> crf;
    unordered_map<string, string> fc;
    unordered_map<string, int> fr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i<n; i++) {
            int r = ratings[i];
            string f = foods[i];
            string c = cuisines[i];
            fr[f] = r;
            crf[c].insert({-r, f});
            fc[f] = c;
        }
    }
    
    void changeRating(string f, int newRating) {
        string c = fc[f];
        int oR  = fr[f];
        crf[c].erase({-oR, f});
        crf[c].insert({-newRating, f});
        fr[f] = newRating;
    }
    
    string highestRated(string c) {
        return begin(crf[c])->second; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(f,newRating);
 * string param_2 = obj->highestRated(c);
 */
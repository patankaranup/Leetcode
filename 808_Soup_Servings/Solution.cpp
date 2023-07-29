class Solution {
public:
    vector<vector<int>> options = {
        {100,0},
        {75,25},
        {50,50},
        {25,75}
    };
    vector<vector<double>> memo;
    double solve(int type_a_n_quantity, int type_b_n_quantity){
        if(type_a_n_quantity<=0 && type_b_n_quantity<=0){
            return 0.5;
        }
        if(type_a_n_quantity<=0){
            return 1.0;
        }
        if(type_b_n_quantity<=0){
            return 0.0;
        }
        if(memo[type_a_n_quantity][type_b_n_quantity] != -1){
            return memo[type_a_n_quantity][type_b_n_quantity];
        }
        double prob = 0.0;
        for(auto &option : options){
            int serve_a = option[0];
            int serve_b = option[1];
            prob += solve(type_a_n_quantity - serve_a,type_b_n_quantity-serve_b);
        }
        return memo[type_a_n_quantity][type_b_n_quantity] = 0.25 * prob;
    };
    double soupServings(int n) {
        if(n>4800){
            return 1;
        }
        memo.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
    };
};
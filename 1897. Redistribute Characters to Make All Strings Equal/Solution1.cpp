class Solution1 {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int  freq[26] = {0};
        for(auto &word : words){
            for(auto &ch : word){
                freq[ch-'a']++;
            }
        }
        // making lambda function 
        // & is used to access varibles outside the scope of lambda function 
        // Here & is used for accessing n 
        // in the parameters we have the content of the given container that is freq 
        auto lambda = [&](int frq_cnt){
            // operations inside here 
            return (frq_cnt % n) == 0;
        };
        // stl all_of takes contaner and check for all the values the given lmabda function 
        return all_of(begin(freq),end(freq),lambda);
    }
};
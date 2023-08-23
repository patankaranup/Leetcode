class Solution {
public:
    typedef pair<int, char> p;
    
    string reorganizeString(string s) {
        int n = s.length();
        
        vector<int> count(26, 0);
        // stroing frequency of characters 
        // 0 -> a , 1 -> b and so on
        for(char &ch : s) {
            count[ch-'a']++;
            // if at anytime the frequency of character become greater than half of the size of n than return empty string 
            if(count[ch-'a'] > (n+1)/2){
                return "";
            }
        }

        // make max heap 
        priority_queue<p, vector<p>> max_heap;
        // iterate over alphabets from a to z convert it to 0 to 25 and check in count vector
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] > 0) {
                max_heap.push({count[ch-'a'], ch});
            }
        }
        
        string str = "";
        // make the string 
        while(max_heap.size() >= 2) {
            // pop two characters at a time with highest frequency
            auto P1 = max_heap.top(); 
            max_heap.pop();
            
            auto P2 = max_heap.top();
            max_heap.pop();
            
            str.push_back(P1.second);
            str.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            // after poping elements if the frequency is still greater that 0 we need to put it back in max heap
            if(P1.first > 0)
                max_heap.push(P1);
            
            if(P2.first > 0)
                max_heap.push(P2);
        }
        
        if(!max_heap.empty()){
            str.push_back(max_heap.top().second);
        }
        
        return str;
    }
};
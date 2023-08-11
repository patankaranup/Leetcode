class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        int assignmentIdx = 0;
        while(idx < n){
            char curr_ch = chars[idx];
            int count = 0;
            // find duplicate counts 
            while(idx < n && chars[idx] == curr_ch){
                count++;
                idx++;
            }
            // after that assign the char and count
            chars[assignmentIdx] = curr_ch;
            assignmentIdx++;
            if(count>1){
                string count_string = to_string(count);
                for(char &ch : count_string){
                    chars[assignmentIdx] = ch;
                    assignmentIdx++;
                }
            }
        }
        return assignmentIdx;
    }
};
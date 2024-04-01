class Solution1 {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ') + 1); //Removes the trailing spaces
        int lastSpace = s.find_last_of(' ');
        return lastSpace == string::npos ? s.length() : s.length() - lastSpace - 1;
    }
};
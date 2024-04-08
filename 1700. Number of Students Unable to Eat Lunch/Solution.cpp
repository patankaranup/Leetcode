class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        //arr[0] = count of student who like circular
        //arr[1] = count of student who like square
        int arr[2] = {0};
        for(int &student : students){
            arr[student]++;
        }
        for(int i = 0; i<n; i++) {
            int curr_sandwich = sandwiches[i];
            if(arr[curr_sandwich] == 0){
                return n-i;
            }
            arr[curr_sandwich]--;
        }
        return 0;
    }
};
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       int n =  people.size();
       int i=0;
       int j=n-1;
       int boats =0;
       // sort the array 
       sort(begin(people),end(people));
       while(i<=j){
           if(people[j]+people[i] <= limit){
               i++;
               j--;
            } else{
                j--;
            }
            boats++;
       }
       return boats;

    }
};
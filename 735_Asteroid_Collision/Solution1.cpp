class Solution1 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int &asteroid : asteroids){
            // when collision will happen
            while(!st.empty() && asteroid<0 && st.back()>0){
                int sum = asteroid + st.back();
                if(sum<0){
                    st.pop_back();
                } else if(sum>0){
                    asteroid = 0;
                } else {
                    st.pop_back();
                    asteroid = 0;
                }
            }
            if(asteroid != 0){
                st.push_back(asteroid);
            }
        }
        return st;
    }
};
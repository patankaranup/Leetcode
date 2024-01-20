class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7; 
    // This both methods are another stack questions 
    vector<ll> getNsl(vector<int>& arr, int n){
        vector<ll> result(n,0);
        stack<ll> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();
                }
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<ll> getNsr(vector<int>& arr, int n){
        vector<ll> result(n,0);
        stack<ll> st;
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<ll> NSL = getNsl(arr,n);
        vector<ll> NSR = getNsr(arr,n);
        ll sum = 0;

        for(int i=0; i<n; i++){
            // how many elements in the left and right 
            ll left_nums = i-NSL[i];
            ll right_nums = NSR[i]-i;
            // totalSubarrays means there are this number of subarrays where the min elements is arr[i]
            ll totalSubarrays = left_nums * right_nums;
            ll totalSum = arr[i] * totalSubarrays;
            sum = (sum + totalSum)%MOD; 
        }
        return sum; 
    }
};
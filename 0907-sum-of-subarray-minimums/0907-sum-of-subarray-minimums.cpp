
class Solution {
public:
    // OPTIMAL APPROACH
    vector<int> findpse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                pse[i] = -1;
            }
            else {
                pse[i] = st.top();
            }

            st.push(i);
        }
        return pse;
    }
    vector<int> findnse(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                nse[i] = n;
            }
            else {
                nse[i] = st.top();
            }

            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // BRUTE FORCE
        // int mod=(int)(1e9 +7);
        // int sum=0;
        // for(int i=0;i<arr.size();i++){
        //     int  mini=arr[i];
        //     for(int j=i;j<arr.size();j++){
        //         mini=min(mini,arr[j]);
        //         sum=(sum+mini)%mod;
        //     }
        // }
        // return sum;
        vector<int> pse = findpse(arr);
        vector<int> nse = findnse(arr);
        long long total = 0;
        long long mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + left * right * arr[i]) % mod;
        }
        return total;
    }
};

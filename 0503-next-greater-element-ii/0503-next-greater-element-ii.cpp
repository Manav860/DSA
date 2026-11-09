class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // BRUTE FORCE
        // int n=nums.size();
        // vector<int> v(nums.size(),-1);
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<i+n;j++){
        //         int index=j%n;
        //         if(nums[index]>nums[i]){
        //             v[i]=nums[index];
        //             break;
        //         }
        //     }
        // }
        // return v;
        
        // OPTIMAL 1
        // vector<int> v=nums;
        // vector<int> v1(nums.size(),-1);
        // for(int i=0;i<nums.size();i++){
        //     v.push_back(nums[i]);
        // }
        // stack<int> st;
        // for(int i=v.size()-1;i>=0;i--){
        //     while(!st.empty() && v[i]>=st.top()){
        //         st.pop();
        //     }
        //     if(i<nums.size() && !st.empty()){
        //         v1[i]=st.top();
        //     }
        //     st.push(v[i]);
        // }
        // return v1;

        // OPTIMAL 2
        int n=nums.size();
        vector<int> v(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                v[i]=st.empty() ? -1:st.top();
            }
            st.push(nums[i%n]);
        }
        return v;
    }
};
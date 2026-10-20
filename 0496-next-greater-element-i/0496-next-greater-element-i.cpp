
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // OPTIMAL APPROACH : USING MONOTONIC STACK
        vector<int> v(nums1.size());
        map<int,int> mp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            v[i]=mp[nums1[i]];
        }
        return v;
        // BRUTE FORCE
        // vector<int> v(nums1.size());

        // for (int i = 0; i < nums1.size(); i++) {
        //     v[i]=-1;
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (nums1[i] == nums2[j]) {
        //             for (int k = j + 1; k < nums2.size(); k++) {
        //                 if (nums2[k] > nums1[i]) {
        //                     v[i] = nums2[k];
        //                     break;
        //                 }
        //             }
        //             break;
        //         }
        //     }
        // }

        // return v;
    }
};

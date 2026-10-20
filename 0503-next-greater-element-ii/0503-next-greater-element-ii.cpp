class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,-1);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<i+n;j++){
                int index=j%n;
                if(nums[index]>nums[i]){
                    v[i]=nums[index];
                    break;
                }
            }
        }
        return v;
    }
};
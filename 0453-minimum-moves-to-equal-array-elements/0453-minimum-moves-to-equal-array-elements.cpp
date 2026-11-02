class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            mini=min(mini,nums[i]);
        }
        return sum-n*mini;
    }
};
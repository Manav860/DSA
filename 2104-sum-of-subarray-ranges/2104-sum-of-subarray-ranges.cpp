class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // BRUTE FORCE
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            int mini=nums[i];
            int big=nums[i];
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                big=max(big,nums[j]);
                sum=sum+(big-mini);
            }
        }
        return sum;
    }
};
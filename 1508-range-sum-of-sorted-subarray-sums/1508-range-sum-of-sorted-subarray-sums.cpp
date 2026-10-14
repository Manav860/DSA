class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long sum=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum=sum+nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        long sum1=0;
        for(int i=left-1;i<right;i++){
            sum1=sum1+v[i];
        }
        return sum1% 1000000007;
    }
};
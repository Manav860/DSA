class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            long long prod=1;
            long long lcm1=nums[i];
            long long gcd1=nums[i];
            for(int j=i;j<nums.size();j++){
                lcm1=lcm(lcm1,(long long)nums[j]);
                gcd1=gcd(gcd1,(long long)nums[j]);
                if(nums[j] != 0 && prod > LLONG_MAX / nums[j])
                    break;
                prod=prod*(long long)nums[j];
                if(gcd1 != 0 && lcm1 <= LLONG_MAX / gcd1) {
                    if(prod==lcm1*gcd1){
                        ans = max(ans, j - i + 1);
                    }
                }
            }
        }
        return ans;
        
    }
};
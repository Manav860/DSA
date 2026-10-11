class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(n%(i+1)==0){
                v.push_back(nums[i]*nums[i]);
                continue;
            }
        }
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum=sum+v[i];
        }
        return sum;
        
    }
};
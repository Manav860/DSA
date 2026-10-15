
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int maxi = 0;
        // for (int i = 1; i <= k; i++) {
        //     auto max1 = max_element(nums.begin(), nums.end());
        //     maxi = *max1;

        //     if (i != k) {
        //         nums.erase(max1);
        //     }
        // }

        // return maxi;
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                res =res & nums[i];
                if (res == 0)
                    return 0;
            }
        }
        return max(res, 0);
    }
};
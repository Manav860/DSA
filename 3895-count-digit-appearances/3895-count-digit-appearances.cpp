
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        // optimal approach
        int answer = 0;
        for( int i = 0; i < nums.size(); i++){
            while( nums[i] > 0){
                if(nums[i] % 10 == digit){
                    answer++;
                }
                nums[i] /= 10;
            }
        }
        return answer;
        // map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++) {
        //     int n = nums[i];
        //     if(n == 0) {
        //         mp[0]++;
        //     }
        //     while(n > 0) {
        //         int digit1 = n % 10;
        //         mp[digit1]++;
        //         n = n / 10;
        //     }
        // }
        // return mp[digit];
        
    }
};

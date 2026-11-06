
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long i = num / 3;
        vector<long long> v;
        if(num % 3 == 0) {
            v.push_back(i - 1);
            v.push_back(i);
            v.push_back(i + 1);
        }
        return v;
    }
};

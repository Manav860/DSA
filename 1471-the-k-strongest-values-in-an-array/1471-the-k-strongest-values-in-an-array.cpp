
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m1 = arr[(n - 1) / 2];
        vector<int> v;
        int i = 0;
        int j = n - 1;
        while (v.size() < k) {
            if (abs(arr[i] - m1) > abs(arr[j] - m1)) {
                v.push_back(arr[i]);
                i++;
            }
            else {
                v.push_back(arr[j]);
                j--;
            }
        }
        return v;
    }
};

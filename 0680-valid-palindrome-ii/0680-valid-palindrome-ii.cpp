class Solution {
public:
    bool validPalindrome(string s) {
        string c = s;
        int i = 0;
        int n = s.length();
        int j = n - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                string a = s;
                string b = s;
                a.erase(i, 1);
                b.erase(j, 1);
                string ra = a;
                string rb = b;
                reverse(ra.begin(), ra.end());
                reverse(rb.begin(), rb.end());
                if(a == ra || b == rb) {
                    return true;
                }
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
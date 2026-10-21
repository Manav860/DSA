class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        if(n==2){
            return -1;
        }
        auto mn=min_element(s.begin(),s.end());
        auto max=max_element(s.begin(),s.end());
        if(s[0]==*mn || s[n-1]==*max){
            return 1;
        }
        for(int i=1;i<n-1;i++){
            if(s[i]==*mn || s[i]==*max){
                return 2;
            }
        }
        return 3;
    }
};
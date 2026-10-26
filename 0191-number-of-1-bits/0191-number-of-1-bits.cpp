class Solution {
public:
    int hammingWeight(int n) {
        int s1=0;
        while(n!=0){
            s1+=n%2;
            n=n/2;
        }
        return s1;
    }
};
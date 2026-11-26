class Solution {
public:
    bool canAliceWin(int n) {
        int num = 10;
        while(n >= num) {
            n -= num;
            num--;
            if(n < num) {
                return true;
            }
            n -= num;
            num--;
        }
        return false;
    }
};
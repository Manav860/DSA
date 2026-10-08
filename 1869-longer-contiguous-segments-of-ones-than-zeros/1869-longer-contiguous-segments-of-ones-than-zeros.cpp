class Solution {
public:
    bool checkZeroOnes(string s) {
        int count1=0;
        int count2=0;
        int max1=0;
        int max2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                count1++;
                max1=max(count1,max1);
            }
            else {
                count1=0;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count2++;
                max2=max(count2,max2);
            }
            else {
                count2=0;
            }
        }
        if(max2>max1){
            return true;
        }
        return false;
        
        
    }
};
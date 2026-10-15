class Solution {
public:
    string convertToBase7(int num) {
        int num1=num;
        if(num==0){
            return "0";
        }
        string str;
        while(num!=0){
            str+=to_string(abs(num%7));
            num=abs(num/7);
            
        }
        if(num1<0){
            str+="-";
        }
        reverse(str.begin(),str.end());
        return str;
        
    }
};
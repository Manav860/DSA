class Solution {
public:
    bool isValid(string s) {
        stack<int> s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                s1.push(s[i]);
            }
            else{
                if(s1.empty()){
                    return false;
                }
                char ch=s1.top();
                if((s[i]==')' && ch=='(')|| (s[i]==']' && ch=='[')||(s[i]=='}' && ch=='{')){
                    s1.pop();
                }
                else{
                    return false;
                }
            }
        }
        return s1.empty();
    }
};
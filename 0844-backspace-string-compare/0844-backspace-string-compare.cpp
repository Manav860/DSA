class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(s[i]);
            }
        }
        string ans1="";
        while(!st1.empty()){
            ans1+=(st1.top());
            st1.pop();
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(t[i]);
            }
        }
        string ans2="";
        while(!st2.empty()){
            ans2+=(st2.top());
            st2.pop();
        }
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        if(ans1==ans2){
            return true;
        }
        return false;

    }
};
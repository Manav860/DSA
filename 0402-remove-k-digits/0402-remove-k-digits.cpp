class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string s="";
        int n=num.length();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) {
            return "0";
        }

        while(!st.empty()){
           s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        int i=0;
        while(i<s.length() && s[i]=='0') {
            i++;
        }
        s = s.substr(i);
        if(s.empty()) {
            return "0";
        }
        return s;
    }
};
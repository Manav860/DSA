class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            while(mp[order[i]]>0){
                ans+=order[i];
                mp[order[i]]--;
            }
        }
        for(auto x:mp){
            while(x.second>0){
                ans+=x.first;
                x.second--;
            }
        }
        return ans;
    }
};
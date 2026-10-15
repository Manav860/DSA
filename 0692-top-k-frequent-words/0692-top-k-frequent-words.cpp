class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> v;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for (auto x : mp) {
            v.push_back(x.first);
        }
        sort(v.begin(),v.end(), [&](string a,string b){
            if(mp[a]==mp[b]){
                return a<b;
            }
            return mp[a]>mp[b];
        });
        v.resize(k);
        return v;
        
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m1;
        for(int i=0;i<ransomNote.length();i++){
            m1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            m1[magazine[i]]--;
        }
        for(auto x: m1){
            if(x.second>0){
                return false;
            }
        }
        return true;

        
    }
};
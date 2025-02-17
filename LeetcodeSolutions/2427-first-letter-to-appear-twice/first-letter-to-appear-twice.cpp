class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mp;
        for(auto ch: s){
            if(mp.find(ch)!= mp.end()) return ch;
            else mp[ch]++;
        }
        return ' ';
    }
};
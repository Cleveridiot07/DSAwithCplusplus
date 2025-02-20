class Solution {
    bool compareMap(unordered_map<char,int> mp1,unordered_map<char,int> mp2){
        for( auto it: mp1){
            if (mp2.find(it.first) != mp2.end()){
                if (mp2[it.first] != it.second) return false;
            }else return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char,int> pattern;
        unordered_map<char,int> cstring;
        
        
        int patternSize = p.size();
        int i = 0, j = 0;
        
        while(j<patternSize){
            pattern[p[j]]++;
            if(j<patternSize-1) cstring[s[j]]++;
            j++;
        }
        j--;
        while(j<s.size()){
            cstring[s[j]]++;
            if (compareMap(pattern,cstring)) ans.push_back(i);
            cstring[s[i]]--;
            if(cstring[s[i]] == 0) cstring.erase(s[i]);
            i++;
            j++;
        }

        return ans;
    }
};
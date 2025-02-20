class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int m = s.size();
        int n = p.size();
        if (m < n) return ans; 

        vector<int> freqCountS(26, 0);
        vector<int> freqCountP(26, 0);
       for (int i = 0; i < n; i++) {
            freqCountP[p[i] - 'a']++;
            freqCountS[s[i] - 'a']++;
        }

   
        if (freqCountS == freqCountP) ans.push_back(0);


        for (int i = n; i < m; i++) {
            freqCountS[s[i] - 'a']++;
            freqCountS[s[i - n] - 'a']--;
            if (freqCountS == freqCountP) ans.push_back(i - n + 1);
        }
        
        return ans;
    }
};

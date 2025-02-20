class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int m = s.size();
        int n = p.size();
        if (m < n) return ans;

        vector<int> freqCountS(26, 0);
        vector<int> freqCountP(26, 0);
        int required = 0;

        for (int i = 0; i < n; i++) {
            freqCountP[p[i] - 'a']++;
            freqCountS[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freqCountS[i] != freqCountP[i]) required++;
        }

        int i = 0, j = n;
        while (j <= m) {
            if (required == 0) ans.push_back(i);

            if (freqCountS[s[i] - 'a'] == freqCountP[s[i] - 'a']) 
                required++;

            freqCountS[s[i] - 'a']--;

            if (freqCountS[s[i] - 'a'] == freqCountP[s[i] - 'a']) 
                required--;

            if (j < m) {
                if (freqCountS[s[j] - 'a'] == freqCountP[s[j] - 'a']) 
                    required++;

                freqCountS[s[j] - 'a']++;

                if (freqCountS[s[j] - 'a'] == freqCountP[s[j] - 'a']) 
                    required--;
            }

            i++;
            j++;
        }

        return ans;
    }
};

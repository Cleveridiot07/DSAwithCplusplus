class Solution {
public:
    string removeKdigits(string s, int k) {
        int i = 0; 
        while (s.size() > 0 && k > 0) {
            if (s.size() == 1) {
                s = "";
            }
            else if (s[i] > s[i + 1]) {  
                s.erase(i, 1);  
                k--;
                if (i > 0) i--;  
            } else {
                i++;
            }
        }

        int j = 0;
        while (j < s.size() && s[j] == '0') {
            j++;
        }
        
        s = s.substr(j); 

        return s.empty() ? "0" : s;
    }
};

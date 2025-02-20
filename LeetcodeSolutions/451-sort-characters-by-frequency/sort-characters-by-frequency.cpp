class Solution {
    static bool comparator(pair<char, int> a,pair<char, int> b){
        return a.second>b.second;
    }
public:
    string frequencySort(string s) {
        vector<pair<char, int>> characters(62, {'#', 0});
        for (char ch : s) {
            if ('a' <= ch && ch <= 'z') {
                characters[ch - 'a'] = {ch, characters[ch - 'a'].second + 1};
            } else if ('A' <= ch && ch <= 'Z') {
                characters[26 + (ch - 'A')] = {ch, characters[26 + (ch - 'A')].second + 1};
            }else{
                characters[52 + (ch - '0')] = {ch, characters[52 + (ch - '0')].second + 1};
            }
        }

        sort(characters.begin(), characters.end(), Solution::comparator);
        string ans = "";
        for(int i=0;i<62;i++){
            if(characters[i].second>0){
                string currentString = "";
                int n = characters[i].second;
                while(n--) currentString += characters[i].first;
                ans += currentString;
            }
        }
        
    return ans;
    }
};
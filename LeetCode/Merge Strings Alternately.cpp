#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int maxLength = max(word1.length(), word2.length());

        for (int i = 0; i < maxLength; i++) {
            if (i < word1.length()) {
                merged += word1[i];
            }
            
            if (i < word2.length()) {
                merged += word2[i];
            }
        }

        return merged;        
    }
};
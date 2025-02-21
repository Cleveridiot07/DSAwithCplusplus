class Solution {
public:
    void helper(vector<int> num, int i, int j, vector<vector<int> > &output) {
        if (i == j-1) {
            output.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            helper(num, i+1, j, output);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >output;
        helper(num, 0, num.size(), output);
        return output;
    }
};
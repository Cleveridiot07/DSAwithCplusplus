class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size(), N = n - 2;
        vector<int> coeff(N + 1);
        for (int j = 0; j <= N; j++) coeff[j] = binom10(N, j);
        int f0 = 0, f1 = 0;
        for (int j = 0; j <= N; j++) {
            f0 = (f0 + coeff[j] * (s[j] - '0')) % 10;
            f1 = (f1 + coeff[j] * (s[j + 1] - '0')) % 10;
        }
        return f0 == f1;
    }
private:
    int binom10(int n, int k) {
        int m2 = binom2(n, k), m5 = binom5(n, k);
        for (int x = 0; x < 10; x++)
            if (x % 2 == m2 && x % 5 == m5)
                return x;
        return 0;
    }
    int binom2(int n, int k) {
        return ((n & k) == k) ? 1 : 0;
    }
    int binom5(int n, int k) {
        int res = 1, nn = n, kk = k;
        int t[5][5] = { {1,0,0,0,0}, {1,1,0,0,0}, {1,2,1,0,0}, {1,3,3,1,0}, {1,4,1,4,1} };
        while (nn > 0 || kk > 0) {
            int nd = nn % 5, kd = kk % 5;
            if (kd > nd) return 0;
            res = (res * t[nd][kd]) % 5;
            nn /= 5;
            kk /= 5;
        }
        return res;
    }
};
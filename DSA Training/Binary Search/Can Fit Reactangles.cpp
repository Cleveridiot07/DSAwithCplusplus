//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include <iostream>

using namespace std;

bool canFit(long long s, int n, int w, int h) {
    return (s / w) * (s / h) >= n;
}

long long minSquareSize(int n, int w, int h) {
    long long left = max(w, h), right = (long long)max(w, h) * n, mid;
    
    while (left < right) {
        mid = left + (right - left) / 2;
        if (canFit(mid, n, w, h))
            right = mid;  
        else
            left = mid + 1; 
    }
    
    return left;
}

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    cout << minSquareSize(n, w, h) << endl;
    return 0;
}

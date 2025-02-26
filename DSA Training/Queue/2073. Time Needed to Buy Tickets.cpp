#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <climits>
#include <string>
#include <iostream>
#include <stack>
#include <set>
using namespace std;

// Typedefs
typedef long long ll;
typedef double db;
typedef unsigned int ui;
typedef vector<ll> VT;
typedef pair<int, int> pii;

// Macros
#define sz(x) ((int)((x).size()))
#define max_val(a, b) (a < b ? b : a)
#define min_val(a, b) (a < b ? a : b)
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second

template <typename T>
void printVector(vector<T> &arr) {
    for (int i = 0; i < sz(arr); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int count = 0;

        for (int i = 0; i < tickets.size(); i++) {
            q.push(tickets[i]);
        }

        while (true) {
            int front = q.front();
            q.pop();

            if (front > 0) {
                count++;
                front--;
            }

            if (front == 0 && k == 0) {
                return count;
            }

            if (front > 0) {
                q.push(front);
            }

            if (k == 0) {
                k = q.size() - 1;
            } else {
                k--;
            }
        }
    }
};



class Solution2 {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            int count = 0;
            while(tickets[k] > 0){
                for(int i=0;i<tickets.size();i++){
                    if(tickets[i]>0){
                        tickets[i]--;
                        count++;
                    }
                    if(tickets[k] == 0) return count;
                }
            }
    
            return count;
        }
    };


void clever() {
    // write your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        clever();
    }
    return 0;
}
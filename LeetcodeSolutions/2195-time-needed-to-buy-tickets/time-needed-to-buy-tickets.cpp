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

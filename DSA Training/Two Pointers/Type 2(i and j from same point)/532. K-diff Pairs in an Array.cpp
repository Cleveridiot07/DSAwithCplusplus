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
void printVector(vector<T> &arr)
{
    for (int i = 0; i < sz(arr); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int count = 0;
        while (i <= j && j < nums.size())
        {
            int curr = abs(nums[j] - nums[i]);
            if (i == j)
            {
                j++;
                continue;
            }
            if (curr == k)
            {
                count++;
                j++;
                // To avoid duplicate pairs
                while (j < nums.size() && nums[j] == nums[j - 1])
                    j++;
                continue;
            }
            if (curr <= k)
            {
                j++;
            }
            else
            {
                i++;
            }
        }

        return count;
    }
};

// Better Representation
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int count = 0;
        while (i <= j && j < nums.size())
        {
            if (i == j || nums[j] - nums[i] < k)
            {
                j++;
            }
            else if (nums[j] - nums[i] == k)
            {
                count++;
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1])
                    j++;
                continue;
            }
            else
            {
                i++;
            }
        }

        return count;
    }
};

void clever()
{
    // write your code here
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        clever();
    }
    return 0;
}
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// O(log n)
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int height = 0;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        while (!st.empty())
        {
            auto tp = st.top();
            st.pop();
            TreeNode *cnode = tp.first;
            int currentLevel = tp.second;
            height = max(height, currentLevel);
            if (cnode->right != nullptr)
                st.push({cnode->right, currentLevel + 1});
            if (cnode->left != nullptr)
                st.push({cnode->left, currentLevel + 1});
        }
        return height;
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
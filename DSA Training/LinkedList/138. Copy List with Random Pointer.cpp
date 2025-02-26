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


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(head == nullptr) return head;
            
            Node* temp = head;
            
            while(temp){
                Node* node = new Node(temp->val);
                node->next = temp->next;
                temp->next = node;
                temp = temp->next->next;
            }
    
            Node* curr1 = head;
            Node* curr2 = head->next;
    
            while(curr1 && curr2){
                if(curr1->random != nullptr){
                    curr2->random = curr1->random->next;
                }else{
                    curr2->random = nullptr;
                }
                curr1 = curr1->next->next;
                if(curr2->next != nullptr) curr2 = curr2->next->next;
            }
    
            curr1 = head;
            curr2 = head->next;
            Node* copyHead = curr2;
            
            while(curr1){
                curr1->next = curr1->next->next;
                curr1 = curr1->next;
                if(curr2->next != nullptr){
                    curr2->next = curr2->next->next;
                    curr2 =curr2->next;
                }
            }
            
            return copyHead;
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
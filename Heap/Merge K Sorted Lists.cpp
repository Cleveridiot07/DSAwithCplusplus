#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Define a custom comparator for the priority queue (min-heap).
    // This comparator ensures that the smallest value node is always at the top of the heap.
    struct Compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;  // Compare nodes by their values to build a min-heap.
        }
    };
    
    // Function to merge k sorted linked lists into one sorted linked list.
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority Queue (Min-Heap) to store the nodes based on their values.
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Insert the first node of each list into the priority queue.
        // TC: O(k log k) where k is the number of linked lists.
        for (ListNode* curr : lists) {
            if (curr != nullptr) pq.push(curr);
        }

        // Initialize pointers for the merged linked list.
        ListNode* head = nullptr;  // The head of the merged linked list.
        ListNode* temp = nullptr;  // Temporary pointer to build the merged list.

        // Process the nodes from the priority queue until it's empty.
        while (!pq.empty()) {
            ListNode* curr = pq.top();  // Get the node with the smallest value.
            pq.pop();  // Remove the node from the priority queue.
            
            if (head == nullptr) {  // If this is the first node in the merged list.
                head = curr;
                temp = head;
            } else {
                temp->next = curr;  // Link the current node to the merged list.
                temp = temp->next;  // Move the temporary pointer forward.
            }

            // If the current node has a next node, push it to the priority queue.
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        // Return the head of the merged linked list.
        return head;
    }
};

/* Time Complexity (TC):
   - Building the priority queue with the first node of each list takes O(k log k),
     where k is the number of lists.
   - Processing each node involves inserting and removing it from the priority queue,
     which takes O(log k) for each node. Since there are n nodes in total, the total
     time for this step is O(n log k).
   - Overall, the time complexity is O(n log k), where n is the total number of nodes across all k lists.

   Space Complexity (SC):
   - The priority queue holds at most k elements at any given time (one node from each list).
   - The merged list will contain all n nodes, which contributes O(n) space.
   - Therefore, the space complexity is O(k + n), where n is the total number of nodes and k is the number of lists.
*/


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: node 5 points back to node 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    ListNode* result = obj.detectCycle(head);

    if (result != nullptr) {
        cout << "Cycle starts at node: "
             << result->val << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
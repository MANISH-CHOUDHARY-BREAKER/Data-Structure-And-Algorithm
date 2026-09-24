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

class Solution  {
    public: 
     ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast-> next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
     }
};

int main() {
    //creating linked list
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
head->next->next->next = new ListNode(4);
head->next->next->next->next = new ListNode(5);

Solution obj;
ListNode* middle = obj.middleNode(head);

cout<< "Middle node:"  << middle->val <<endl;

return 0;

}
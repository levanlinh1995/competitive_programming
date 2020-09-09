// problem: 142. Linked List Cycle II
// link: https://leetcode.com/problems/linked-list-cycle-ii/description/
#include <iostream>
using namespace std;

//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(){};
     ListNode(int x) : val(x), next(NULL) {};
 };
class Solution {
public:
    ListNode* createNewNode(int val) {
        ListNode* node = new ListNode(val);
        return node;
    }

    void addAtHead(ListNode* &head, int val) {
        ListNode* newNode = this->createNewNode(val);
        
        newNode->next = head;
        head = newNode;
    }

    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        slow = slow->next;
        fast = fast->next->next;

        while (fast && fast->next)
        {
            if (slow == fast) {
                break;
            }

            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != fast) {
            return NULL;
        }

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

int main() {
    ListNode* head = NULL;

    Solution sl;
    sl.addAtHead(head, 3);
    sl.addAtHead(head, 4);
    sl.addAtHead(head, 5);
    sl.addAtHead(head->next, 5);

    ListNode* node = sl.detectCycle(head);
    
    if (node) {
        cout << node->val;
    } else {
        cout << "do not contain cycle";
    }

    return 0;
}
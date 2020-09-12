// problem: 206. Reverse Linked List
// link: https://leetcode.com/problems/reverse-linked-list/description/

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
    // method1:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* originalNode = head;
    //     ListNode* temp;

    //     while (originalNode != NULL && originalNode->next != NULL)
    //     {
    //         temp = originalNode->next;
    //         originalNode->next = originalNode->next->next;
    //         temp->next = head; 
    //         head = temp;
    //     }

    //     return head;
    // }

    // method2: recursive
    ListNode* reverseList(ListNode* head) {
        head = recursive(head, head);

        return head;
    }

    ListNode* recursive(ListNode* head, ListNode* originalNode) {
        ListNode* temp;

        if (originalNode != NULL && originalNode->next != NULL)
        {
            temp = originalNode->next;
            originalNode->next = originalNode->next->next;
            temp->next = head; 
            head = temp;

            head = recursive(head, originalNode);
        }

        return head;
    }
};
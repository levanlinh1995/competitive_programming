// problem: 19. Remove Nth Node From End of List
// link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* last = head;
        ListNode* prev = head;
        int count = 0;

        while (last->next != NULL)
        {
            if (count >= n) {
                prev = prev->next;
            }

            last = last->next;
            count++;
        }

        ListNode* deletedNode;
        if (count < n) {
            deletedNode = prev;
            head = prev->next;
            delete deletedNode;
        } else {
            deletedNode = prev->next;
            prev->next = deletedNode->next;
            delete deletedNode;
        }

        return head;
    }
};

int main() {


    return 0;
}
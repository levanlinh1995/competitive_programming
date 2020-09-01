// problem: 141. Linked List Cycle
// link: https://leetcode.com/problems/linked-list-cycle/description/

#include <iostream>
#include <unordered_set>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // method 1: time complexity O(n), space complexity O(n)
    // bool hasCycle(ListNode* head) {
    //     if (!head) {
    //         return false;
    //     }

    //     unordered_set<ListNode*> st;

    //     ListNode* p = head;
    //     while (p)
    //     {
    //         if(st.find(p) != st.end()) {
    //             return true;
    //         }

    //         st.insert(p);
    //         p = p->next;
    //     }
        
    //     return false;
    // }

    // method 2: time complexity O(n), space complexity O(1)
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast)
        {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};
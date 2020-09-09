// problem: 160. Intersection of Two Linked Lists
// link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // method 1: frute force O(n*m)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* pa;
    //     ListNode* pb;

    //     for (pa = headA; pa != NULL; pa = pa->next)
    //     {
    //         for (pb = headB; pb != NULL; pb = pb->next)
    //         {
    //             if (pa == pb && pa != NULL) {
    //                 return pa;
    //             }
    //         }
    //     }
        
    //     return NULL;
    // }

    // method 2: hash set force O(n+m)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode*> hashset;
    //     ListNode* pa;
    //     ListNode* pb;

    //     for (pa = headA; pa != NULL; pa = pa->next)
    //     {
    //         hashset.insert(pa);
    //     }

    //     for (pb = headB; pb != NULL; pb = pb->next)
    //     {
    //         if (hashset.count(pb) > 0) {
    //             return pb;
    //         }
    //     }
        
    //     return NULL;
    // }

    // method 3: two pointer O(n+m)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA;
        ListNode* pb = headB;

        while (pa != pb)
        {
            pa = (pa != NULL) ? pa->next : headB;
            pb = (pb != NULL) ? pb->next : headA;
        }

        return pa;
    }
};

int main() {


    return 0;
}
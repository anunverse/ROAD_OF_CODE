// https://leetcode-cn.com/explore/learn/card/linked-list/195/classic-problems/753/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *tail, *evenhead, *eventail;
        tail = head;
        evenhead = tail->next;
        eventail = evenhead;
        while (tail != NULL && tail->next != NULL && eventail->next != NULL)
        {
            tail->next = eventail->next;
            tail = tail->next;
            eventail->next = tail ->next;
            eventail = eventail->next;
        }
        tail->next = evenhead;
        return head;
    }
};

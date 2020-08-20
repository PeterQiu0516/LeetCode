/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
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
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;

        // double pointer
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second-half list
        ListNode *secondHalf = slow->next;
        slow->next = nullptr;
        secondHalf = reverse(secondHalf);

        //insert the second-half back into the raw list
        ListNode *firstHalf = head;
        while (firstHalf&& secondHalf)
        {
            // get the node from secondHalf
            ListNode *currNext = secondHalf;
            secondHalf = secondHalf->next;

            ListNode *firstNext = firstHalf->next; // store the next Node of firstHalf
            currNext->next = firstHalf->next;
            firstHalf->next = currNext; // insert the currNext
            firstHalf = firstNext;
        }
    }

    ListNode *reverse(ListNode *head)
    {

        ListNode *newHead = NULL;
        ListNode *prevHead = head;
        ListNode *tmp;

        while (prevHead)
        {
             // store the prevHead
            tmp = prevHead->next;

            // insert the first node of prevHead at the front of newHead
            prevHead->next = newHead;
            newHead = prevHead; 
            
            prevHead = tmp;
        }

        return newHead;
    }
};
// @lc code=end

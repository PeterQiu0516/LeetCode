/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *tmp = head;
        while (tmp != nullptr && tmp->next != nullptr)
        {
            if (tmp->val == tmp->next->val)
            {
                ListNode *victim = tmp->next;
                tmp->next = tmp->next->next;
                delete victim;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        return head;
    }
}

;
// @lc code=end

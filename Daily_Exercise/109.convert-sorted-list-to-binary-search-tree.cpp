/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // Since the list is the in-order traversal of the tree, we don't have to search for median, just follow that step
    TreeNode* buildTree(ListNode*& curr, int start, int end){
        if(start > end) return nullptr;
        int mid = (start+end+1)/2; // 0, 1, 2, 3, 4; 2->1->0
        TreeNode* root = new TreeNode;
        root->left = buildTree(curr,start,mid-1); // left subtree
        root->val = curr->val; // root
        curr = curr->next;
        root->right = buildTree(curr,mid+1,end); // right subtree
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        int len = 1;
        ListNode* tmp = head;
        while((tmp = tmp->next)) len++;
        return buildTree(head,0,len-1);
    }
};
// @lc code=end


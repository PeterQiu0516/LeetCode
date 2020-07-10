/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;

        // recursion
        // preorder_helper(root,res);

        // iteration using stack
        if (root == nullptr)
            return {};
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node *temp = stk.top();
            stk.pop();
            for (int i = temp->children.size() - 1; i >= 0; i--)
                stk.push(temp->children[i]);
            res.push_back(temp->val);
        }

        return res;
    }

    void preorder_helper(Node *cur, vector<int> &res)
    {
        if (cur == nullptr)
            return;
        res.push_back(cur->val);
        for (auto child : cur->children)
            preorder_helper(child, res);
    }
};
// @lc code=end

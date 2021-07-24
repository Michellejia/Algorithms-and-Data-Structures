#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<int> res;

public:
    // recursive
    vector<int> preorderTraversal_v1(TreeNode *root)
    {
        if (root == nullptr)
            return res;
        else
        {
            res.push_back(root->val);
            preorderTraversal_v1(root->left);
            preorderTraversal_v1(root->right);
        }
        return res;
    }

    // iteration
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode *> st;
        TreeNode *top;
        st.push(root);
        while (!st.empty())
        {
            top = st.top();
            res.push_back(top->val);
            st.pop();
            if (top->right)
                st.push(top->right);
            if (top->left)
                st.push(top->left);
        }
        return res;
    }
};

int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n5.right = &n6;

    TreeNode *root = &n1;
    Solution s;
    vector<int> res = s.preorderTraversal(root);
    for (int &a : res)
    {
        printf("%d\n", a);
    }
}
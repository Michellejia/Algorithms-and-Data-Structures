#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        TreeNode *tmp = root;
        queue<TreeNode *> q;
        q.push(tmp);
        while (!q.empty())
        {
            int index = q.size();
            res.push_back(vector<int>());
            for (int i = 0; i < index; i++)
            {
                tmp = q.front();
                q.pop();
                res.back().push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
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
    vector<vector<int>> res = s.levelOrder(root);
    for (vector<int> &a : res)
    {
        for(int &b: a)
            printf("%d\n", b);
    }
}
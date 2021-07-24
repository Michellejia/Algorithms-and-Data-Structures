#include <iostream>
#include <vector>
#include <queue>
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
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> q;
        TreeNode *tmp = root;
        if (root == nullptr)
            return 0;

        int res = 0;
        q.push(tmp);
        while (!q.empty())
        {
            int index = q.size();
            res++;
            for (int i = 0; i < index; i++)
            {
                tmp = q.front();
                q.pop();
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
    printf("%d\n", s.maxDepth(&n1));
}
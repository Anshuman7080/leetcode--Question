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
 class box {
public:
    int sum = 0;
    int min;
    int max;
    bool isBst;

    box(int data) {
        sum = data;
        min = data;
        max = data;
        isBst = true;
    }

    box() {
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
        isBst = true;
    }
};

class Solution {
public:
    box* solve(TreeNode* root, int &maxSum) {
        if (!root->left && !root->right) {
            maxSum = max(maxSum, root->val);
            return new box(root->val);
        } else if (!root->left && root->right) {
            box* head = solve(root->right, maxSum);
            if (head->isBst && head->min > root->val) {
                head->sum += root->val;
                head->min = root->val;
                maxSum = max(maxSum, head->sum);
                return head;
            } else {
                head->isBst = false;
                return head;
            }
        } else if (!root->right && root->left) {
            box* head = solve(root->left, maxSum);
            if (head->isBst && head->max < root->val) {
                head->sum += root->val;
                head->max = root->val;
                maxSum = max(maxSum, head->sum);
                return head;
            } else {
                head->isBst = false;
                return head;
            }
        } else {
            box* left = solve(root->left, maxSum);
            box* right = solve(root->right, maxSum);
            box* head = new box();
            if (left->isBst && right->isBst && left->max < root->val && right->min > root->val) {
                head->sum = left->sum + right->sum + root->val;
                head->isBst = true;
                head->max = right->max;
                head->min = left->min;
                maxSum = max(maxSum, head->sum);
                return head;
            } else {
                head->isBst = false;
                return head;
            }
        }
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};

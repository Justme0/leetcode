#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cassert>



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* createBinaryTree(std::vector<std::vector<int>>& descriptions) {
            TreeNode *root = nullptr;
            std::map<int, TreeNode*> m;

            for (auto desc : descriptions) {
                int parentV = desc[0];
                int childV = desc[1];
                bool bLeft = desc[2];

                // must establish for parent if not exists
                TreeNode *&parent = m[parentV];
                if (nullptr == parent) {
                    parent = new TreeNode(parentV);
                    root = parent; // key
                }

                // firstly must query child if exists,
                // maybe created as parent
                TreeNode *&child = m[childV];
                if (nullptr == child) {
                    child = new TreeNode(childV);
                }

                if (bLeft) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }

                c2p[childV] = parentV;
            }

            return root;

        }
};

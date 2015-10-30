class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (nullptr == root) {
			return root;
		}

		invertTree(root->left);
		invertTree(root->right);

		std::swap(root->left, root->right);

		return root;
	}
};

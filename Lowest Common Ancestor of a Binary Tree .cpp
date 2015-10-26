/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined 

between two nodes v and w as the lowest node in T that has 

both v and w as descendants (where we allow a node to be a descendant of itself).¡±

Ñ°ÕÒ¹²Í¬×æÏÈ
*/

#include "lib.h"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return nullptr;
		if (root == p || root == q) return root;
		TreeNode* L = lowestCommonAncestor(root->left, p, q);
		TreeNode* R = lowestCommonAncestor(root->right, p, q);
		if (L && R) return root;
		return L ? L : R;
	}
};
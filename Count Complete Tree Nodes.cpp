/*
计算完全二叉树的节点数
*/
#include"lib.h"
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == nullptr){
			return 0;
		}
		TreeNode *leftPtr = root->left, *rightPtr = root->right;
		int layers = 1;
		while (leftPtr != nullptr && rightPtr != nullptr){
			leftPtr = leftPtr->left;
			rightPtr = rightPtr->right;
			++layers;
		}
		if (leftPtr != nullptr || rightPtr != nullptr){
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
		//return pow(2,layers) - 1;
		return (1 << layers) - 1;//位操作在测试时减少了一半时间
	}
};
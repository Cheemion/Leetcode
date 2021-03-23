#include<iostream>
#include<list>
using std::list;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


class Solution {
public:

    TreeNode* commonAncestor(TreeNode* root, int o1, int o2) {
        if(root == nullptr) return nullptr;
        if(root->val == o1 || root->val == o2) return root;
        TreeNode* left = commonAncestor(root->left, o1, o2);
        TreeNode* right = commonAncestor(root->right, o1, o2);
        if(right != nullptr && left != nullptr)
            return root;
        if(right == nullptr)
            return left;
        else
            return right;
    }

    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        return commonAncestor(root, o1, o2)->val;
    }
};

int main(){
    std::cout << "11" << std::endl;
    return 1;
}
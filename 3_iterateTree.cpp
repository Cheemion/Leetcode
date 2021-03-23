#include<iostream>
#include<vector>
using std::vector;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    
    void preOrder(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }

    void middleOrder (TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        middleOrder(root->left, vec);
        vec.push_back(root->val);
        middleOrder(root->right, vec);
    }

    void postOrder(TreeNode* root, vector<int>& vec){
        if(root == nullptr) return;
        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);
    }

    vector<vector<int> > threeOrders(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> pre;
        preOrder(root, pre);
        vector<int> middle;
        middleOrder(root, middle);
        vector<int> post;
        postOrder(root, post);
        
        result.push_back(pre);
        result.push_back(middle);
        result.push_back(post);
        return result;
    }
};

int main(int, char**) {

    std::cout << "Hello, world!\n";
    return 0;
}
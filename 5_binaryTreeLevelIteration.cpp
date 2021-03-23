#include<iostream>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
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
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if(!root) return result;
        q.push(root);
        while(!q.empty()) {
            vector<int> layer;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                layer.emplace_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);

                if(q.front()->right)
                    q.push(q.front()->right);

                q.pop();
            }
            result.emplace_back(layer);
        }
        return result;
    }
};


int main(){
    return 0;
}
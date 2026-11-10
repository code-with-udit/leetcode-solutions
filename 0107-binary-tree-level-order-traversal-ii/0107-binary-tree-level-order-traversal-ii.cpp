class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if (root == NULL) return ans;
        vector<int>temp;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back({temp});
                temp.clear();
                if(!q.empty())q.push(NULL);
            }
            else {
                temp.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;  // Use multiset for sorting
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int hd = pos.first, lv = pos.second;
            mp[hd][lv].insert(node->val);  // multiset maintains sorting
            
            if (node->left)
                q.push({node->left, {hd - 1, lv + 1}});
            if (node->right)
                q.push({node->right, {hd + 1, lv + 1}});
        }

        for (auto& [hd, levels] : mp) {
            vector<int> temp;
            for (auto& [lv, nodes] : levels) {
                temp.insert(temp.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

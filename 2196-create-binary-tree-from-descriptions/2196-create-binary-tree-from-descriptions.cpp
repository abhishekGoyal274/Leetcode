class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal  = desc[1];
            int isLeft    = desc[2];

            if (!map[parentVal]) map[parentVal] = new TreeNode(parentVal);
            if (!map[childVal])  map[childVal]  = new TreeNode(childVal);

            if (isLeft) map[parentVal]->left  = map[childVal];
            else map[parentVal]->right = map[childVal];
            children.insert(childVal);
        }

        for (auto& [val, node] : map)
            if (!children.count(val)) 
                return node;
        
        return nullptr;
    }
};
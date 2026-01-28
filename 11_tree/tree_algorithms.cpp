#include <bits/stdc++.h>
using namespace std;

// ===========================================
// TREE ALGORITHMS - Comprehensive Guide
// ===========================================

// ========== TREE NODE DEFINITION ==========

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// General tree with multiple children
struct TreeNodeGeneral {
    int val;
    vector<TreeNodeGeneral*> children;
    TreeNodeGeneral(int x) : val(x) {}
};

// ========== TREE TRAVERSAL ==========

// Inorder: Left -> Root -> Right
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Inorder Iterative
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    
    while (root || !st.empty()) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        result.push_back(root->val);
        root = root->right;
    }
    
    return result;
}

// Preorder Iterative
vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st;
    st.push(root);
    
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    
    return result;
}

// Postorder Iterative
vector<int> postorderIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    stack<TreeNode*> st1, st2;
    st1.push(root);
    
    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);
        
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    
    while (!st2.empty()) {
        result.push_back(st2.top()->val);
        st2.pop();
    }
    
    return result;
}

// Level Order Traversal (BFS)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(level);
    }
    
    return result;
}

// ========== TREE PROPERTIES ==========

// Height of tree
int height(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

// Diameter of tree (longest path between any two nodes)
int diameterHelper(TreeNode* root, int& diameter) {
    if (!root) return 0;
    
    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);
    
    diameter = max(diameter, leftHeight + rightHeight);
    
    return 1 + max(leftHeight, rightHeight);
}

int getDiameter(TreeNode* root) {
    int diameter = 0;
    diameterHelper(root, diameter);
    return diameter;
}

// Check if tree is balanced
bool isBalanced(TreeNode* root) {
    function<int(TreeNode*)> check = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int leftHeight = check(node->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = check(node->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        return 1 + max(leftHeight, rightHeight);
    };
    
    return check(root) != -1;
}

// Subtree sum
int subtreeSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + subtreeSum(root->left) + subtreeSum(root->right);
}

// Count total nodes
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ========== BINARY SEARCH TREE ==========

// BST Validation
bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

// Search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    
    if (root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Insert in BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertBST(root->right, val);
    }
    
    return root;
}

// Delete from BST
TreeNode* deleteBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    
    if (val < root->val) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->val) {
        root->right = deleteBST(root->right, val);
    } else {
        // Node found
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Two children: find inorder successor
        TreeNode* minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        
        root->val = minNode->val;
        root->right = deleteBST(root->right, minNode->val);
    }
    
    return root;
}

// ========== PATH AND DISTANCE ==========

// Lowest Common Ancestor
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

// LCA for BST
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestorBST(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestorBST(root->right, p, q);
    }
    
    return root;
}

// Path Sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

// All paths with target sum
void getPathSum(TreeNode* root, int targetSum, vector<int>& path, 
                vector<vector<int>>& result) {
    if (!root) return;
    
    path.push_back(root->val);
    
    if (!root->left && !root->right && root->val == targetSum) {
        result.push_back(path);
    } else {
        getPathSum(root->left, targetSum - root->val, path, result);
        getPathSum(root->right, targetSum - root->val, path, result);
    }
    
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    getPathSum(root, targetSum, path, result);
    return result;
}

// Maximum Path Sum
int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    
    int leftSum = max(0, maxPathSum(root->left, maxSum));
    int rightSum = max(0, maxPathSum(root->right, maxSum));
    
    maxSum = max(maxSum, root->val + leftSum + rightSum);
    
    return root->val + max(leftSum, rightSum);
}

// ========== TREE DP ==========

// House Robber III - Max sum without adjacent nodes
pair<int, int> robHelper(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto [leftRob, leftNoRob] = robHelper(root->left);
    auto [rightRob, rightNoRob] = robHelper(root->right);
    
    int rob = root->val + leftNoRob + rightNoRob;
    int noRob = max(leftRob, leftNoRob) + max(rightRob, rightNoRob);
    
    return {rob, noRob};
}

int rob(TreeNode* root) {
    auto [robVal, noRobVal] = robHelper(root);
    return max(robVal, noRobVal);
}

// ========== CONSTRUCTION ==========

// Build tree from inorder and preorder
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    
    int preIdx = 0;
    
    function<TreeNode*(int, int)> build = [&](int inStart, int inEnd) -> TreeNode* {
        if (inStart > inEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int inIdx = inorderMap[root->val];
        
        root->left = build(inStart, inIdx - 1);
        root->right = build(inIdx + 1, inEnd);
        
        return root;
    };
    
    return build(0, inorder.size() - 1);
}

// Serialize tree to string
string serialize(TreeNode* root) {
    string result;
    
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) {
            result += "null,";
            return;
        }
        result += to_string(node->val) + ",";
        dfs(node->left);
        dfs(node->right);
    };
    
    dfs(root);
    return result;
}

// Deserialize string to tree
TreeNode* deserialize(string data) {
    queue<string> q;
    string word = "";
    
    for (char c : data) {
        if (c == ',') {
            if (word != "") q.push(word);
            word = "";
        } else {
            word += c;
        }
    }
    
    function<TreeNode*()> dfs = [&]() -> TreeNode* {
        if (q.empty()) return nullptr;
        
        string val = q.front();
        q.pop();
        
        if (val == "null") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = dfs();
        root->right = dfs();
        
        return root;
    };
    
    return dfs();
}

// ========== UTILITY FUNCTIONS ==========

void printTree(TreeNode* root, int level = 0) {
    if (!root) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) cout << "  ";
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

// Create sample tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

// ========== EXAMPLE USAGE ==========

int main() {
    // Create sample tree
    TreeNode* root = createSampleTree();
    
    cout << "=== Tree Traversals ===" << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    cout << "Level Order:" << endl;
    auto levels = levelOrder(root);
    for (auto& level : levels) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
    
    cout << "\n=== Tree Properties ===" << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Diameter: " << getDiameter(root) << endl;
    cout << "Is Balanced: " << (isBalanced(root) ? "Yes" : "No") << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Subtree Sum: " << subtreeSum(root) << endl;
    
    cout << "\n=== Path Sum ===" << endl;
    cout << "Has path sum 38: " << (hasPathSum(root, 38) ? "Yes" : "No") << endl;
    auto paths = pathSum(root, 38);
    cout << "Paths with sum 38: " << paths.size() << endl;
    
    cout << "\n=== Tree Structure ===" << endl;
    printTree(root);
    
    return 0;
}

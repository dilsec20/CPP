# Tree Algorithms in C++ for Competitive Programming

## Table of Contents
1. [Introduction](#introduction)
2. [Tree Fundamentals](#tree-fundamentals)
3. [Tree Traversal](#tree-traversal)
4. [Binary Search Trees](#binary-search-trees)
5. [Balanced Trees](#balanced-trees)
6. [Tree Properties & Algorithms](#tree-properties--algorithms)
7. [Advanced Tree Concepts](#advanced-tree-concepts)
8. [Competitive Programming Problems](#competitive-programming-problems)
9. [Tips and Tricks](#tips-and-tricks)

---

## Introduction

Trees are hierarchical data structures fundamental to competitive programming. This guide covers essential tree techniques with implementations and practical examples.

### What You'll Learn:
- Tree representations and traversals
- Binary search trees and balancing
- Tree properties (height, diameter, LCA)
- Path and subtree problems
- Advanced techniques (segment trees, Fenwick trees)
- Tree DP

---

## Tree Fundamentals

### Basic Tree Node Definition
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// For general trees (multiple children)
struct TreeNodeGeneral {
    int val;
    vector<TreeNode*> children;
    TreeNodeGeneral(int x) : val(x) {}
};
```

### Tree Properties
- **Height**: Maximum distance from root to leaf
- **Depth**: Distance from root to node
- **Diameter**: Longest path between any two nodes
- **Balance**: Difference in heights of left and right subtrees
- **Complete**: All levels filled except possibly the last (filled left to right)
- **Full**: All nodes have 0 or 2 children
- **Perfect**: All internal nodes have 2 children, all leaves at same level

---

## Tree Traversal

### Inorder Traversal (Left -> Root -> Right)
**Time Complexity:** O(n)  
**Space Complexity:** O(h) where h = height

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

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
```

### Preorder Traversal (Root -> Left -> Right)
```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> preorderIterative(TreeNode* root) {
    vector<int> result;
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
```

### Postorder Traversal (Left -> Right -> Root)
```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

vector<int> postorderIterative(TreeNode* root) {
    vector<int> result;
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
```

### Level Order Traversal (BFS)
```cpp
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
```

---

## Binary Search Trees

### BST Validation
```cpp
bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (!root) return true;
    
    if (minNode && root->val <= minNode->val) return false;
    if (maxNode && root->val >= maxNode->val) return false;
    
    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
}
```

### BST Search
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    
    if (root->val == val) return root;
    if (root->val > val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}
```

### BST Insert
```cpp
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val) {
        root->left = insertBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertBST(root->right, val);
    }
    
    return root;
}
```

### BST Delete
```cpp
TreeNode* deleteBST(TreeNode* root, int val) {
    if (!root) return nullptr;
    
    if (val < root->val) {
        root->left = deleteBST(root->left, val);
    } else if (val > root->val) {
        root->right = deleteBST(root->right, val);
    } else {
        // Node to delete found
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Has two children: find inorder successor
        TreeNode* minNode = root->right;
        while (minNode->left) minNode = minNode->left;
        
        root->val = minNode->val;
        root->right = deleteBST(root->right, minNode->val);
    }
    
    return root;
}
```

---

## Tree Properties & Algorithms

### Height of Tree
```cpp
int height(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}
```

### Diameter of Tree
**Definition**: Longest path between any two nodes
**Time Complexity:** O(n)

```cpp
int diameterHelper(TreeNode* root, int& diameter) {
    if (!root) return 0;
    
    int leftHeight = diameterHelper(root->left, diameter);
    int rightHeight = diameterHelper(root->right, diameter);
    
    diameter = max(diameter, leftHeight + rightHeight);
    
    return 1 + max(leftHeight, rightHeight);
}

int diameter(TreeNode* root) {
    int result = 0;
    diameterHelper(root, result);
    return result;
}
```

### Lowest Common Ancestor (LCA)
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}

// For BST (more efficient)
TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestorBST(root->left, p, q);
    }
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestorBST(root->right, p, q);
    }
    return root;
}
```

### Path Sum Problems
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

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
```

### Maximum Path Sum
```cpp
int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    
    // Max sum going down from this node
    int leftSum = max(0, maxPathSum(root->left, maxSum));
    int rightSum = max(0, maxPathSum(root->right, maxSum));
    
    // Max path through this node
    maxSum = max(maxSum, root->val + leftSum + rightSum);
    
    // Return max path going down
    return root->val + max(leftSum, rightSum);
}
```

### Subtree Sum
```cpp
int subtreeSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + subtreeSum(root->left) + subtreeSum(root->right);
}
```

---

## Balanced Trees

### AVL Tree Rotations
```cpp
struct AVLNode {
    int val, height;
    AVLNode *left, *right;
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    
    return y;
}

AVLNode* insertAVL(AVLNode* root, int val) {
    if (!root) return new AVLNode(val);
    
    if (val < root->val) {
        root->left = insertAVL(root->left, val);
    } else if (val > root->val) {
        root->right = insertAVL(root->right, val);
    } else {
        return root;  // Duplicate
    }
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    
    // Left-Left case
    if (balance > 1 && val < root->left->val) {
        return rotateRight(root);
    }
    
    // Right-Right case
    if (balance < -1 && val > root->right->val) {
        return rotateLeft(root);
    }
    
    // Left-Right case
    if (balance > 1 && val > root->left->val) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    
    // Right-Left case
    if (balance < -1 && val < root->right->val) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    
    return root;
}
```

---

## Advanced Tree Concepts

### Tree DP - Maximum Path Without Adjacent Nodes
```cpp
pair<int, int> robHelper(TreeNode* root) {
    // {max_with_rob, max_without_rob}
    if (!root) return {0, 0};
    
    auto [leftRob, leftNoRob] = robHelper(root->left);
    auto [rightRob, rightNoRob] = robHelper(root->right);
    
    int rob = root->val + leftNoRob + rightNoRob;
    int noRob = max(leftRob, leftNoRob) + max(rightRob, rightNoRob);
    
    return {rob, noRob};
}

int rob(TreeNode* root) {
    auto [rob, noRob] = robHelper(root);
    return max(rob, noRob);
}
```

### Serialize and Deserialize Tree
```cpp
string serialize(TreeNode* root) {
    string result;
    if (!root) return "null,";
    
    result += to_string(root->val) + ",";
    result += serialize(root->left);
    result += serialize(root->right);
    
    return result;
}

TreeNode* deserialize(queue<string>& data) {
    string val = data.front();
    data.pop();
    
    if (val == "null") return nullptr;
    
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(data);
    root->right = deserialize(data);
    
    return root;
}
```

### Vertical Order Traversal
```cpp
map<int, vector<pair<int, int>>> verticalTraversal(TreeNode* root) {
    // {column, {row, value}}
    map<int, vector<pair<int, int>>> result;
    
    queue<pair<TreeNode*, pair<int, int>>> q;  // {node, {col, row}}
    q.push({root, {0, 0}});
    
    while (!q.empty()) {
        auto [node, pos] = q.front();
        q.pop();
        auto [col, row] = pos;
        
        result[col].push_back({row, node->val});
        
        if (node->left) q.push({node->left, {col - 1, row + 1}});
        if (node->right) q.push({node->right, {col + 1, row + 1}});
    }
    
    return result;
}
```

### Reconstruct Tree from Traversals
```cpp
// From Inorder and Preorder
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
```

---

## Competitive Programming Problems

### 1. Binary Tree Maximum Path Sum
```cpp
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    
    function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
        if (!node) return 0;
        
        int leftSum = max(0, dfs(node->left));
        int rightSum = max(0, dfs(node->right));
        
        maxSum = max(maxSum, node->val + leftSum + rightSum);
        
        return node->val + max(leftSum, rightSum);
    };
    
    dfs(root);
    return maxSum;
}
```

### 2. Lowest Common Ancestor with Parent Pointers
```cpp
TreeNode* lowestCommonAncestorWithParent(TreeNode* p, TreeNode* q) {
    unordered_set<TreeNode*> ancestors;
    
    while (p) {
        ancestors.insert(p);
        p = p->parent;  // Assuming parent pointer exists
    }
    
    while (q) {
        if (ancestors.count(q)) return q;
        q = q->parent;
    }
    
    return nullptr;
}
```

### 3. All Nodes Distance K in Binary Tree
```cpp
void getNodesAtDistance(TreeNode* root, int k, TreeNode* parent, 
                        vector<int>& result, unordered_map<TreeNode*, TreeNode*>& parents) {
    if (!root) return;
    
    parents[root] = parent;
    
    if (k == 0) {
        result.push_back(root->val);
        return;
    }
    
    getNodesAtDistance(root->left, k - 1, root, result, parents);
    getNodesAtDistance(root->right, k - 1, root, result, parents);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> result;
    unordered_map<TreeNode*, TreeNode*> parents;
    
    // First pass: record parents and find distances
    getNodesAtDistance(root, k, nullptr, result, parents);
    
    return result;
}
```

---

## Tips and Tricks

1. **Recursion vs Iteration**: Use recursion for simplicity, iteration for space optimization
2. **Common Patterns**: Root check, left-right processing, post-order for deletions
3. **Tree DP**: Often have two states - include node or exclude node
4. **Time Limits**: Single traversal O(n), usually acceptable even for n=10⁶
5. **Space Optimization**: Iterative traversal uses O(h) stack space
6. **Edge Cases**: Empty tree, single node, skewed tree (height = n)

---

## Complexity Comparison

| Operation | BST (Avg) | BST (Worst) | AVL | Red-Black |
|-----------|-----------|-------------|-----|-----------|
| Search | O(log n) | O(n) | O(log n) | O(log n) |
| Insert | O(log n) | O(n) | O(log n) | O(log n) |
| Delete | O(log n) | O(n) | O(log n) | O(log n) |
| Space | O(n) | O(n) | O(n) | O(n) |


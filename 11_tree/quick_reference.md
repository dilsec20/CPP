# Tree Algorithms - Quick Reference

## Time Complexities Cheat Sheet

| Operation | Time | Space | Notes |
|-----------|------|-------|-------|
| Traversal | O(n) | O(h) | h = height, O(n) for skewed |
| Search BST | O(log n) | O(h) | Worst case O(n) |
| Insert BST | O(log n) | O(h) | Worst case O(n) |
| Delete BST | O(log n) | O(h) | Worst case O(n) |
| Height | O(n) | O(h) | Must visit all |
| LCA | O(n) | O(h) | Stored parent O(h) |
| Diameter | O(n) | O(h) | Single pass |
| Is Balanced | O(n) | O(h) | Must check all |

---

## Code Templates

### 1. TreeNode Definition
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### 2. Inorder Traversal (Recursive)
```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

### 3. Inorder Traversal (Iterative)
```cpp
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

### 4. Preorder Traversal (Recursive)
```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

### 5. Postorder Traversal (Recursive)
```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### 6. Level Order Traversal (BFS)
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

### 7. Height of Tree
```cpp
int height(TreeNode* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}
```

### 8. Is Balanced
```cpp
int checkBalance(TreeNode* root) {
    if (!root) return 0;
    
    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1;
    
    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1) return -1;
    
    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}
```

### 9. Lowest Common Ancestor
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    if (left && right) return root;
    return left ? left : right;
}
```

### 10. LCA for BST
```cpp
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
```

### 11. Diameter of Tree
```cpp
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
```

### 12. Path Sum
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}
```

### 13. Maximum Path Sum
```cpp
int maxPathSum(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    
    int leftSum = max(0, maxPathSum(root->left, maxSum));
    int rightSum = max(0, maxPathSum(root->right, maxSum));
    
    maxSum = max(maxSum, root->val + leftSum + rightSum);
    
    return root->val + max(leftSum, rightSum);
}
```

### 14. Invert Binary Tree
```cpp
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}
```

### 15. Validate BST
```cpp
bool isValidBST(TreeNode* root, long long minVal = LLONG_MIN, long long maxVal = LLONG_MAX) {
    if (!root) return true;
    
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}
```

### 16. Build Tree from Inorder & Preorder
```cpp
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

### 17. Serialize & Deserialize
```cpp
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
```

### 18. Flatten Tree to Linked List
```cpp
void flatten(TreeNode* root) {
    if (!root) return;
    
    function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) -> TreeNode* {
        if (!node) return nullptr;
        if (!node->left && !node->right) return node;
        
        TreeNode* leftTail = dfs(node->left);
        TreeNode* rightTail = dfs(node->right);
        
        if (leftTail) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        
        return rightTail ? rightTail : leftTail;
    };
    
    dfs(root);
}
```

### 19. House Robber III (Tree DP)
```cpp
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
```

### 20. Subtree of Another Tree
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    
    return p->val == q->val &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false;
    
    if (isSameTree(root, subRoot)) return true;
    
    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}
```

---

## Common Patterns

### Pattern 1: DFS for Path Problems
```cpp
void dfs(TreeNode* node, int target, vector<int>& path, vector<vector<int>>& result) {
    if (!node) return;
    
    path.push_back(node->val);
    
    // Check if leaf and valid
    if (!node->left && !node->right && target == node->val) {
        result.push_back(path);
    } else {
        dfs(node->left, target - node->val, path, result);
        dfs(node->right, target - node->val, path, result);
    }
    
    path.pop_back();
}
```

### Pattern 2: Tree DP - Two States
```cpp
pair<int, int> dp(TreeNode* node) {
    if (!node) return {0, 0};
    
    auto [incLeft, excLeft] = dp(node->left);
    auto [incRight, excRight] = dp(node->right);
    
    int include = node->val + excLeft + excRight;
    int exclude = max(incLeft, excLeft) + max(incRight, excRight);
    
    return {include, exclude};
}
```

### Pattern 3: Finding Property (Height, Diameter)
```cpp
int findProperty(TreeNode* node, int& globalMax) {
    if (!node) return 0;
    
    int left = findProperty(node->left, globalMax);
    int right = findProperty(node->right, globalMax);
    
    globalMax = max(globalMax, left + right);  // or other formula
    
    return 1 + max(left, right);
}
```

### Pattern 4: BST Operations
```cpp
TreeNode* search(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return search(root->left, val);
    return search(root->right, val);
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}
```

---

## Tips & Tricks

1. **Recursive vs Iterative**: Recursion simpler, iteration saves stack space
2. **Return Values**: Use -1 or INT_MIN for "invalid" in DFS
3. **Global State**: Use reference parameters for global max/count
4. **Parent Pointers**: Store during traversal for efficient LCA
5. **Memory**: Be careful with new TreeNode allocations
6. **Edge Cases**: Null root, single node, skewed tree

---

## Common Mistakes

❌ Forgetting base case in recursion  
❌ Modifying tree without careful handling  
❌ Wrong traversal order for specific problem  
❌ Integer overflow in sum calculations  
❌ Not handling negative values in BST  
❌ Incorrect comparisons in BST operations  
❌ Memory leaks from new allocations  
❌ Stack overflow on very deep trees  

---

## Quick Decision Tree

**Need traversal?**
- Inorder → BST (sorted), values in order
- Preorder → Build tree, root processing first
- Postorder → Delete, leaf processing first
- Level-order → BFS, by depth

**Need to check property?**
- Path exists → DFS, early termination
- Max/Min value → DFS with global variable
- Count nodes → Postorder
- Height/Balance → Bottom-up computation

**Working with BST?**
- Validate → Track min/max at each node
- Search → Use BST property
- Delete → Handle three cases carefully

**Tree DP?**
- Define states → Include/exclude or other criterion
- Recurrence → Combine child states
- Return → What goes up to parent

---

## Input/Output Patterns

### Reading Tree from Array
```cpp
TreeNode* buildFromArray(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    for (int i = 1; i < arr.size(); i += 2) {
        TreeNode* node = q.front();
        q.pop();
        
        if (arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        
        if (i + 1 < arr.size() && arr[i + 1] != -1) {
            node->right = new TreeNode(arr[i + 1]);
            q.push(node->right);
        }
    }
    
    return root;
}
```

### Print Tree
```cpp
void printTree(TreeNode* root, int level = 0) {
    if (!root) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) cout << "  ";
    cout << root->val << endl;
    printTree(root->left, level + 1);
}
```

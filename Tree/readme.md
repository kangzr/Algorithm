### 树的一些特性

#### 二叉树
每个节点最多两个子节点

- 满二叉树： 所有叶子节点都在同一层
- 完全二叉树： 所有节点位置与满二叉树相同
- 二叉搜索树：中序遍历为升序, 查找时间复杂度为O(logn) , n 为树的高度

```数据结构
// Definition for a binary tree node
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};
```


#### B树
多路平衡二叉树，每个节点既有包含数据又包含索引

#### B+树
仅叶子节点包含数据，非叶子节点为索引，且所有叶子节点由链表链接,大部分数据库用B+树做索引



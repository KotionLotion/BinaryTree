
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>

class BinaryTree
{
private:
    struct TreeNode
    {
        int num;
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode(int val) : num(val), leftChild(nullptr), rightChild(nullptr) {}
    };

    TreeNode *treeRoot;

    // Helper func
    TreeNode *addNode(TreeNode *current, int value);
    TreeNode *findNode(TreeNode *current, int value) const;
    TreeNode *removeNode(TreeNode *current, int value);
    TreeNode *getMinValueNode(TreeNode *current);
    void printInorder(TreeNode *current) const;
    void printPreorder(TreeNode *current) const;
    void printPostorder(TreeNode *current) const;
    int countAllNodes(TreeNode *current) const;
    int getTreeDepth(TreeNode *current) const;
    void clearTree(TreeNode *current);

public:
    BinaryTree();
    ~BinaryTree();

    // interface
    void insert(int value);
    bool contains(int value) const;
    void deleteValue(int value);
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void levelorder() const;
    int size() const;
    int depth() const;
};

#endif